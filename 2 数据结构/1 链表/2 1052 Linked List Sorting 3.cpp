#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
const int INF=0x7fffffff;
struct node {
	int addr,data,next;
	int flg;
} L[N];

int cmp(node a,node b){
	if(!a.flg || !b.flg) 
		return a.flg>b.flg;//��ķ�ǰ�棬Ҳ������Ч�ڵ��ǰ�� 
	else return a.data<b.data;
}
int n,s1;//��ʼ�ڵ�

int main() {
	cin>>n>>s1;
	for(int i=0; i<N; i++) L[i].flg=0; //��Ч�ڵ�
	for(int i=0; i<n; i++) {
		int a,b,c;
		cin>>a>>c>>b;
		L[a].addr=a;
		L[a].data=c;
		L[a].next=b;
	}
	int p=s1,cnt=0;
	while(p!=-1) {
		L[p].flg=1;//��ע��Ч�ڵ�
		p=L[p].next;
		cnt++;
	}
	if(!cnt) printf("0 -1");
	else {
		sort(L,L+N,cmp);
		printf("%d %05d\n",cnt,L[0].addr);
		for(int i=0;i<cnt;i++){
			if(i!=cnt-1){//�������һ��
				printf("%05d %d %05d\n",L[i].addr,L[i].data,L[i+1].addr);
			}
			else printf("%05d %d -1\n",L[i].addr,L[i].data);
		}
	}
	return 0;
}
