#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1005;
const int INF=0x3fffffff;
struct Node {
	int next;
	int d;
	int c;
};
vector<Node>e[N];
int dis[N];
int cost[N];
int vis[N];//已经扩展了的node
int n,m;//点数，边数
int sn,en;//起点，终点
void Dijkstra() {
	fill(dis,dis+N,INF);
	fill(cost,cost+N,INF);
	memset(vis,0,sizeof(vis));
	dis[sn]=0;
	cost[sn]=0;
	vis[sn]=1;

	int p=sn;
	for(int i=1; i<n; i++) {
		for(int j=0; j<e[p].size(); j++) {
			int t=e[p][j].next;
//			cout<<p<<' '<<t<<' ';
			if(vis[t]) continue;
			int d=e[p][j].d;
			int c=e[p][j].c;
			if(dis[t]==INF || dis[t]>dis[p]+d || 
			   dis[t]==dis[p]+d && cost[t]>cost[p]+c) {
				dis[t]=dis[p]+d;
				cost[t]=cost[p]+c;
			} 
		}
		int mi_d=INF, mi_c=INF;
		for(int j=1; j<=n; j++) {
			if(vis[j] || dis[j]==INF) continue;
			if(dis[j]<mi_d) {
				mi_d=dis[j];
				p=j;
			} 
//			else if(dis[j]==mi_d && cost[j]<mi_c) {
//				mi_c=cost[j];
//				p=j;
//			}
		}
		vis[p]=1;
	}
}//本质就是在frontier里选，so去掉已经扩展的和完全未知的
int main() {
	while(scanf("%d%d", &n,&m)!=EOF) {
		if(!n&&!m) break;
		for(int i=1; i<=n; i++) e[i].clear();
		while(m--) {
			int a,b,d,c;
			scanf("%d%d%d%d", &a,&b,&d,&c);
			Node t;
			t.next=b;
			t.d=d;
			t.c=c;
			e[a].push_back(t);
			t.next=a;
			e[b].push_back(t);
		}
		scanf("%d%d", &sn,&en);
		Dijkstra();
		printf("%d %d\n", dis[en], cost[en]);
	}
	return 0;
}
