#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int N=100005;
struct node{
	char data;
	int next;
	int ap;//出现 
}L[N];//L[i]表示i指向的元素 

int main(){
	int s1,s2,n;
	scanf("%d %d %d",&s1,&s2,&n);
	while(n--){
		int a,b;
		char c;
		scanf("%d %c %d",&a,&c,&b);
//		cin>>a>>c>>b;
		L[a].next=b;
		L[a].data=c;
	}
	for(int i=s1;i!=-1;i=L[i].next){//注意是i!--1，如果写next的话，如果刚开始就是-1，压根没有next呢 
		L[i].ap=1;
	}
	for(int i=s2;i!=-1;i=L[i].next){
		if(L[i].ap==1){
			printf("%05d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
