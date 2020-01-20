#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=205;
const int INF=0x3fffffff;
struct Node {
	int next;
	int cost;
};
vector<Node>e[N];//邻接链表存图
int n,m;//路口数，道路数
int dis[N];//存：从s到i的最短路
int mark[N];//标记是否已经得到：到i的最短路长度（即 是否已经在S集里）

void Dijkstra() {
	fill(dis,dis+N,INF);
	memset(mark,0,sizeof(mark));
	dis[1]=0;//到自己
	mark[1]=1;
	
	int p=1;//指新加的node
	for(int i=1; i<n; i++) { //n-1次，确定n-1个点的最短路 
		for(int j=0; j<e[p].size(); j++) { //遍历新加的点的all邻边
			int t=e[p][j].next;
			if(mark[t]) continue;
			int c=e[p][j].cost;
			if(dis[t]==INF || dis[t]>dis[p]+c)//t节点尚不可达，or由p到t更短
				dis[t]=dis[p]+c;
		}
		int mi=INF;
		for(int j=1; j<=n; j++) { //选下一个最短路的node
			if(mark[j] || dis[j]==INF) continue;
			if(dis[j]<mi) {
				mi=dis[j];
				p=j;
			}
		}
		mark[p]=1;
	}
}
int main() {
	while(scanf("%d%d", &n,&m)!=EOF) {
		if(!n&&!m) break;
		for(int i=1; i<=n; i++) e[i].clear();
		while(m--) {
			int a,b,c;
			scanf("%d%d%d", &a,&b,&c);
			Node t;
			t.next=b;
			t.cost=c;
			e[a].push_back(t);
			t.next=a;//无向图，两个方向都要添加
			e[b].push_back(t);
		}
		Dijkstra();
		printf("%d\n", dis[n]);
	}
	return 0;
}
