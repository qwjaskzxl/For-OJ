#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
const int N=1004;
vector<int>e[N];
int layer[N]= {0};
int vis[N]= {0};
int n,L,k,ans;//人数，层数限制

void BFS(int x) {
	queue<int>q;
	q.push(x);
	while(!q.empty()) {
		int t=q.front();
//		cout<<t<<' ';
		if(layer[t]>=L) break;
		q.pop();
		for(int i=0; i<e[t].size(); i++) {
			int nd=e[t][i];
			if(vis[nd]) continue;
			vis[nd]=1;
			layer[nd]=layer[t]+1;
			q.push(nd);
			ans++;
		}
	}
}

int main() {
	cin>>n>>L;
	for(int i=1,a,t; i<=n; i++) {
		cin>>t;
		while(t--) {
			cin>>a;
			e[a].push_back(i);
		}
	}
	cin>>k;
	while(k--) {
		int x;
		cin>>x;
		ans=0;
		memset(layer,0,sizeof(layer));
		memset(vis,0,sizeof(vis));
		vis[x]=1;
		BFS(x);
		cout<<ans<<endl;
	}
	return 0;
}
