#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=1005;
const int INF=0x7fffffff;
int is_1=0;
string a,b;
struct node {
	char data;
	node *lchild;
	node *rchild;
};
node *create() { //返回指针，也就是地址
	node *T=new node;
	T->lchild=T->rchild=NULL;
	return T;
}
void layer_order(node *T) {
	if(T==NULL) return ;
	queue<node*>q;
	q.push(T);
	while(!q.empty()){
		T=q.front();
		q.pop();
		if(!is_1) {
			cout<<T->data;
			is_1=1;
		}
		else cout<<' '<<T->data;
		if(T->lchild!=NULL) q.push(T->lchild);
		if(T->rchild!=NULL) q.push(T->rchild);
	}
}
node *build(int poL,int poR, int inL,int inR) {
	node *T=create();
	T->data=a[poR];//根的value
	int k;//根在中序遍历中的index 
	for(k=inL;k<=inR;k++) 
		if(b[k]==T->data)
			break;
	int numL=k-inL;//中序遍历序列中，左子树的长度
	if(k>inL) T->lchild=build(poL,poL+numL-1,inL,k-1);//非常好理解啦！ 
	if(k<inR) T->rchild=build(poL+numL,poR-1,k+1,inR);
	return T;
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	node *T=build(0,n-1, 0,n-1);
	layer_order(T);
	return 0;
}
/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
