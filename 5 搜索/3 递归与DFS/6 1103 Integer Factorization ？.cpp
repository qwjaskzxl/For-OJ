#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100005;
const int INF=0x7fffffff;
int po(int a,int b) {
	int ans=1;
	while(b!=0) {
		if(b&1)
			ans*=a;
		b>>=1;
		a*=a;
	}
	return ans;
}
int n,k,p;//N��������ָ��
vector<int>fac;//�������ӵĵ���
vector<int>ans,tmp;
int maxF=-1;
void DFS(int idx,int nowK,int sumN,int sumF) {
	if(sumN>n) return ;
	if(nowK==k) {
		if(sumN==n) {
			if(sumF>maxF) {
				ans=tmp;
				maxF=sumF;
			}
		}
		return ;
	}

	if(idx>=1) { //��Ϊ����idx-1���Ҫ�ѵ�
		tmp.push_back(idx);
		DFS(idx,nowK+1,sumN+fac[idx],sumF+idx);//ѡ
		tmp.pop_back();
		DFS(idx-1,nowK,sumN,sumF);//��ѡ
	}
}

int main() {
	cin>>n>>k>>p;
	for(int i=0; i<n; i++) {
		int t=po(i,p);
		if(t<n)
			fac.push_back(t);
		else break;
	}
	int L=fac.size();
	DFS(L-1,0,0,0);
	if(maxF==-1) printf("Impossible");
	else {
		printf("%d = ",n);
		for(int i=0; i<k-1; i++) 
			printf("%d^%d + ", ans[i],p);
		printf("%d^%d", ans[k-1],p);
	}
	return 0;
}
