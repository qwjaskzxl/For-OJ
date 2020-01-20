#include<iostream>
#include<vector>
using namespace std;
struct node {
	int data;
	node *lchild;
	node *rchild;
};
vector<int>ori,pre,mir_pre,ans;//ans放正确的树的后序遍历

node *create() {
	node *T=new node;
	T->lchild=T->rchild=NULL;
	return T;
}
node *insert(node *T, int x) {
	if(T==NULL) {
		T=create();
		T->data=x;
	} else if(x<T->data)
		T->lchild=insert(T->lchild,x);
	else
		T->rchild=insert(T->rchild,x);
	return T;
}
void preOrder(node *T) {
	if(T!=NULL) pre.push_back(T->data);
	if(T->lchild!=NULL) preOrder(T->lchild);
	if(T->rchild!=NULL) preOrder(T->rchild);
}
void mir_preOrder(node *T) {
//	swap(T->lchild,T->rchild);
	if(T!=NULL) mir_pre.push_back(T->data);
	if(T->rchild!=NULL) mir_preOrder(T->rchild);
	if(T->lchild!=NULL) mir_preOrder(T->lchild);
}
void postOrder(node *T) {
	if(T->lchild!=NULL) postOrder(T->lchild);
	if(T->rchild!=NULL) postOrder(T->rchild);
	if(T!=NULL) ans.push_back(T->data);
}
void mir_postOrder(node *T) {
	if(T->rchild!=NULL) mir_postOrder(T->rchild);
	if(T->lchild!=NULL) mir_postOrder(T->lchild);
	if(T!=NULL) ans.push_back(T->data);
}
int main() {
	int n,x;
	cin>>n;
	node *T=NULL;
	for(int i=0;i<n;i++) {
		scanf("%d",&x);
		ori.push_back(x);
		T=insert(T,x);
	}
	preOrder(T);
	mir_preOrder(T);
	if(ori!=pre && ori!=mir_pre) {
		printf("NO");
		return 0;
	}
	if(ori==pre) postOrder(T);
	else if(ori==mir_pre) mir_postOrder(T);
	printf("YES\n");
	for(int i=0; i<n-1; i++)
		printf("%d ",ans[i]);
	printf("%d",ans[n-1]);
	return 0;
}
