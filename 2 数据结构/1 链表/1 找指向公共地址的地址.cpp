#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int N=100005;
struct node{
	char data;
	int next;
	int ap;//���� 
}L[N];//L[i]��ʾiָ���Ԫ�� 

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
	for(int i=s1;i!=-1;i=L[i].next){//ע����i!--1�����дnext�Ļ�������տ�ʼ����-1��ѹ��û��next�� 
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
