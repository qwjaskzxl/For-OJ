#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=1005;
vector<int>e[N];
int n,m,k;//城市，路，query
int q,ans=-1;//query
int vis[N]= {0};
/*
注意：还是要先存一个edge，然后在相应的query时做联通操作
*/
void DFS(int x) {
	for(int j=0; j<e[x].size(); j++) {
		int nd=e[x][j];
		if(nd!=q && !vis[nd]) {
			vis[nd]=1;
			DFS(e[x][j]);
		}
	}
}
int main() {
	cin>>n>>m>>k;
	while(m--) {
		int a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	while(k--) {
		cin>>q;
		ans=-1;
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++)
			if(i!=q && !vis[i]) {
				ans++;
				DFS(i);
			}
		printf("%d\n",ans);
	}
	return 0;
}
