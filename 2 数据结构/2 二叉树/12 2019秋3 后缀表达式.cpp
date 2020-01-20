#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_map>
#include<map>
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
struct node {
	string op;
	int l,r;
} v[N];

int dfs(int T) {
	cout<<'(';
	if(v[T].op=="+" || v[T].op=="-") {
		if(v[T].l!=-1&&v[T].r==-1 || v[T].l==-1&&v[T].r!=-1) {//是符号位 
			cout<<v[T].op;
			if(v[T].l!=-1) dfs(v[T].l);
			if(v[T].r!=-1) dfs(v[T].r);
		} else {//是操作符 
			if(v[T].l!=-1) dfs(v[T].l);
			if(v[T].r!=-1) dfs(v[T].r);
			cout<<v[T].op;
		}
	} else {
		if(v[T].l!=-1) dfs(v[T].l);
		if(v[T].r!=-1) dfs(v[T].r);
		cout<<v[T].op;
	}
	cout<<')';
}
int isRoot[N]= {0};
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>v[i].op>>v[i].l>>v[i].r;
		if(v[i].l!=-1) isRoot[v[i].l]=1;
		if(v[i].r!=-1) isRoot[v[i].r]=1;
	}
	int root;
	for(root=1; isRoot[root]!=0; root++);
	dfs(root);
	return 0;
}
/*
2329
ans:17137
*/
