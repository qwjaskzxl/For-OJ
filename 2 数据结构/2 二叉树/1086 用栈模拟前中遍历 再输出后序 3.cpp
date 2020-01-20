#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
struct node {
	int data;
	node* lchild,*rchild;
};
int n,fir=0;
vector<int>preS,inS;
stack<int>st;

node* create() {
	node *T=new node;
	T->lchild=T->rchild=NULL;
	return T;
}
void postOrder(node *T) {
	if(T->lchild!=NULL) postOrder(T->lchild);
	if(T->rchild!=NULL) postOrder(T->rchild);
	if(!fir) {
		cout<<T->data;
		fir=1;
	} else cout<<' '<<T->data;
}
node* build(int preL,int preR, int inL,int inR) {
	node *T=create();
	T->data=preS[preL];//cout<<T->data<<' ';
	int k;
	for(k=inL; k<=inR; k++) {
		if(inS[k]==T->data)
			break;
	}
	int numL=k-inL;
	if(k>inL) T->lchild=build(preL+1,preL+numL,inL,k-1);
	if(k<inR) T->rchild=build(preL+numL+1,preR,k+1,inR);
	return T;
}

int main() {
	cin>>n;
	for(int i=0,j; i<2*n; i++) {
		string a;
		cin>>a;
		if(a=="Push") {
			cin>>j;
			preS.push_back(j);
			st.push(j);
		} else {
			inS.push_back(st.top());
			st.pop();
		}
	}
	node *T=build(0,n-1,0,n-1);
	postOrder(T);
	return 0;
}
