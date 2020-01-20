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
		return a.flg>b.flg;//大的放前面，也就是有效节点放前面 
	else return a.data<b.data;
}
int n,s1;//开始节点

int main() {
	cin>>n>>s1;
	for(int i=0; i<N; i++) L[i].flg=0; //无效节点
	for(int i=0; i<n; i++) {
		int a,b,c;
		cin>>a>>c>>b;
		L[a].addr=a;
		L[a].data=c;
		L[a].next=b;
	}
	int p=s1,cnt=0;
	while(p!=-1) {
		L[p].flg=1;//标注有效节点
		p=L[p].next;
		cnt++;
	}
	if(!cnt) printf("0 -1");
	else {
		sort(L,L+N,cmp);
		printf("%d %05d\n",cnt,L[0].addr);
		for(int i=0;i<cnt;i++){
			if(i!=cnt-1){//不到最后一点
				printf("%05d %d %05d\n",L[i].addr,L[i].data,L[i+1].addr);
			}
			else printf("%05d %d -1\n",L[i].addr,L[i].data);
		}
	}
	return 0;
}
