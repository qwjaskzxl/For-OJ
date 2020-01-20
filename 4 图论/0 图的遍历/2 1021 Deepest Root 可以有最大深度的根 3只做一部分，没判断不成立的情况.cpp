#include<bits/stdc++.h>
#include<cmath>
#include<queue>
using namespace std;
const int N=10005;
vector<int>e[N];
int n,maD=-1;
int layer[N];//layer[i]:以i为根的最大深度
int vis[N];
void DFS(int x,int dep) {
	int isLeaf=1;
	for(int i=0; i<e[x].size(); i++) {
		int nd=e[x][i];
		if(vis[nd]) continue;
//		cout<<nd<<' ';
		isLeaf=0;
		vis[nd]=1;
		DFS(nd,dep+1);
		vis[nd]=0;
	}
	if(isLeaf) {
//		cout<<dep<<"a\n";
		if(dep>maD)
			maD=dep;
	}
}
int main() {
	cin>>n;
	for(int i=1,a,b; i<n; i++) {
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1; i<=n; i++) {
		memset(vis,0,sizeof(vis));
		maD=-1;
		vis[i]=1;
		DFS(i,1);
		layer[i]=maD;
	}
	maD=-1;
	for(int i=1; i<=n; i++)
		if(maD<layer[i])
			maD=layer[i];
	for(int i=1,j=0; i<=n; i++)
		if(maD==layer[i]) {
			printf("%d\n",i);
		}
	return 0;
}
