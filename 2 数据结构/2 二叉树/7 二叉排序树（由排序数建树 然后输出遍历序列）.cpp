#include<iostream>
using namespace std;
struct node {
	node *lchild;
	node *rchild;
	int data;
};
node *creat() {
	node *T=new node;
	T->lchild=T->rchild=NULL;
	return T;
}
node *preorder(node *T) {
	if(T!=NULL) printf("%d ", T->data);
	if(T->lchild!=NULL) preorder(T->lchild);
	if(T->rchild!=NULL) preorder(T->rchild);
}
node *inorder(node *T) {
	if(T->lchild!=NULL) inorder(T->lchild);
	if(T!=NULL) printf("%d ", T->data);
	if(T->rchild!=NULL) inorder(T->rchild);
}
node *postorder(node *T) {
	if(T->lchild!=NULL) postorder(T->lchild);
	if(T->rchild!=NULL) postorder(T->rchild);
	if(T!=NULL) printf("%d ", T->data);
}

node *insert(node *T, int x) {
	if(T==NULL) {//���жϵ�������ʱ�򣬿�ʼҲ��NULL������main��������ĵ�һ���ڵ�Ҳ�ǳ�ʼ��ΪNULL 
		T=creat();
		T->data=x;
	} else if(x<T->data) {
		T->lchild=insert(T->lchild,x);
	} else if(x>T->data) {//����˵��Ҫ����ظ�Ԫ�أ���������ȵ�ֵ��������Ķ�һ�� 
		T->rchild=insert(T->rchild,x);
	}
	return T;
}
int main() {
	int n,x;
	while(cin>>n) {
		node *T=NULL;//��дcreatΪ���ж��ǵ�һ���ڵ㣬��insert����������creat
		for(int i=0; i<n; i++) {
			cin>>x;
			T=insert(T,x);//�������ܲ��϶� T����
		}
		preorder(T); printf("\n");
		inorder(T); printf("\n");
		postorder(T); printf("\n");
	}
	return 0;
}
