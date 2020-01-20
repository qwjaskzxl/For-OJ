#include<iostream>
using namespace std;
struct node {
	node *lchild;
	node *rchild;
	char data;
};
int idx;//标记str的index 
string s;

node *creat() {
	node *T=new node;//一定要new，意思是分配内存 
	T->lchild=T->rchild=NULL;//左右子树为空
	return T;
}

node *build(char c) {
	node *T=creat();//指针
	if(c=='#')
		T=NULL;
	else {
		T->data=c;
		T->lchild=build(s[++idx]);
		T->rchild=build(s[++idx]);
	}
	return T;
}
void in_order(node *T) {
	if(T->lchild!=NULL)
		in_order(T->lchild);
	printf("%c ", T->data);
	if(T->rchild!=NULL)
		in_order(T->rchild);
}
int main() {
	while(cin>>s) {
		idx=0;//输入每个样例都要初始化 
		node *T=build(s[0]);
		in_order(T);
		printf("\n");		
	}
	return 0;
}
