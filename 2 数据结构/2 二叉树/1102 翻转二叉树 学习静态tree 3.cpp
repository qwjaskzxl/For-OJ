#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=105;
struct node {
//	int data;
	int lchild,rchild;
	int isroot;
} tree[N];
int n,fir1=0,fir2=0;
void rev(int T) { //·´×ª
	if(T==-1) return ;
	rev(tree[T].lchild);
	rev(tree[T].rchild);
	swap(tree[T].lchild,tree[T].rchild);
}
void BFS(int T) {
	queue<int>q;
	q.push(T);
	while(!q.empty()) {
		int t=q.front();
		q.pop();
		if(!fir1) {
			fir1=1;
			printf("%d", t);
		} else printf(" %d", t);
		if(tree[t].lchild!=-1) q.push(tree[t].lchild);
		if(tree[t].rchild!=-1) q.push(tree[t].rchild);
	}
}
void inOrder(int T) {
	if(tree[T].lchild!=-1) inOrder(tree[T].lchild);
	if(!fir2) {
		fir2=1;
		printf("%d", T);
	} else printf(" %d", T);
	if(tree[T].rchild!=-1) inOrder(tree[T].rchild);
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++) tree[i].isroot=1;
	for(int i=0; i<n; i++) {
		char c	;
		cin>>c;
		if(c=='-') tree[i].lchild=-1;
		else {
			tree[i].lchild=c-'0';
			tree[c-'0'].isroot=0;
		}
		cin>>c;
		if(c=='-') tree[i].rchild=-1;
		else {
			tree[i].rchild=c-'0';
			tree[c-'0'].isroot=0;
		}
	}
	int root=0;
	for(; tree[root].isroot!=1; root++); //ÕÒµ½root
	rev(root);
	BFS(root);
	printf("\n");
	inOrder(root);
	return 0;
}
