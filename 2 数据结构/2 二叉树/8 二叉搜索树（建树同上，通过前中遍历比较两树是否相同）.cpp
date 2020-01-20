#include<iostream>
using namespace std;
struct node {
	node *lchild;
	node *rchild;
	char data;//char类型也可以直接比较数字的大小
};
string s0,s;//记录排序树序列。每个样例对应每个s，都和s0比
string s1,s2;//记录两个树的 前中遍历序列

node *creat() {
	node *T=new node;
	T->lchild=T->rchild=NULL;
	return T;
}
node *insert(node *T, char x) {
	if(T==NULL) {
		T=creat();
		T->data=x;
	} else if(x<T->data) {
		T->lchild=insert(T->lchild,x);
	} else if(x>T->data) {
		T->rchild=insert(T->rchild,x);
	}
	return T;
}
node *preorder(node *T,int k) {
	if(T!=NULL) {
		if(k==1) s1+=T->data;
		else if(k==2) s2+=T->data;
	}
	if(T->lchild!=NULL) preorder(T->lchild,k);
	if(T->rchild!=NULL) preorder(T->rchild,k);
}
node *inorder(node *T,int k) {
	if(T->lchild!=NULL) inorder(T->lchild,k);
	if(T!=NULL) {
		if(k==1) s1+=T->data;
		else if(k==2) s2+=T->data;
	}
	if(T->rchild!=NULL) inorder(T->rchild,k);
}
int main() {
	int n;
	while(cin>>n>>s0, n!=0) {
		s1="";
		node *T1=NULL;
		for(int i=0; i<s0.length(); i++) {
			T1=insert(T1,s0[i]);
		}
		preorder(T1,1);
		inorder(T1,1);
		while(n--) {
			s2="";
			cin>>s;
			node *T2=NULL;
			for(int i=0; i<s.length(); i++) {
				T2=insert(T2,s[i]);
			}
			preorder(T2,2);
			inorder(T2,2);
//			cout<<s1<<"   "<<s2<<endl;
			if(s1==s2) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
