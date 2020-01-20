#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 32623//int(sqrt(1e9))+1
int prime[maxn];
int mark[maxn];//��1��ʼ 
int pri_n=0;
//��Ȼ���ݷ�Χ��10^9�����Ƕ����һ�� > sqrt(10^9)������ ��������������������������жϼ���
void search_pri() {
	memset(mark,0,sizeof(mark));
	for(int i=2; i<maxn; i++) {
		if(mark[i]) continue;
		prime[pri_n++]=i;
		if(i>int(sqrt(maxn))) continue;//������		
		for(int j=i*i; j<maxn; j+=i)
			mark[j]=1;
	}
}
int main() {//15:27-15:54
	search_pri();
	int n;
	while(scanf("%d", &n) != EOF) {
		int cnt=0;
		for(int i=0; n>=prime[i]&&i<pri_n; i++) {
			while(n%prime[i]==0) { //��while����if
				n/=prime[i];
				cnt++;
			}
		}
		if(n!=1) cnt++;//˵������һ��>32623������ 
		cout<<cnt<<'\n';
	}
	return 0;
}
