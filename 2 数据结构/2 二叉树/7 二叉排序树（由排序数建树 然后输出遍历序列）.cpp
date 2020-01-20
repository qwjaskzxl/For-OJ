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
	if(T==NULL) {//在判断到子树的时候，开始也是NULL。所以main里，整个树的第一个节点也是初始化为NULL 
		T=creat();
		T->data=x;
	} else if(x<T->data) {
		T->lchild=insert(T->lchild,x);
	} else if(x>T->data) {//本题说不要输出重复元素，不考虑相等的值。否则插哪都一样 
		T->rchild=insert(T->rchild,x);
	}
	return T;
}
int main() {
	int n,x;
	while(cin>>n) {
		node *T=NULL;//不写creat为了判断是第一个节点，在insert函数里面再creat
		for(int i=0; i<n; i++) {
			cin>>x;
			T=insert(T,x);//这样才能不断对 T更新
		}
		preorder(T); printf("\n");
		inorder(T); printf("\n");
		postorder(T); printf("\n");
	}
	return 0;
}
