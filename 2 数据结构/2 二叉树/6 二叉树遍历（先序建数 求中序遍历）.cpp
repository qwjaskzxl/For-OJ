#include<iostream>
using namespace std;
struct node {
	node *lchild;
	node *rchild;
	char data;
};
int idx;//���str��index 
string s;

node *creat() {
	node *T=new node;//һ��Ҫnew����˼�Ƿ����ڴ� 
	T->lchild=T->rchild=NULL;//��������Ϊ��
	return T;
}

node *build(char c) {
	node *T=creat();//ָ��
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
		idx=0;//����ÿ��������Ҫ��ʼ�� 
		node *T=build(s[0]);
		in_order(T);
		printf("\n");		
	}
	return 0;
}
