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
vector<Node>e[N];//�ڽ������ͼ
int n,m;//·��������·��
int dis[N];//�棺��s��i�����·
int mark[N];//����Ƿ��Ѿ��õ�����i�����·���ȣ��� �Ƿ��Ѿ���S���

void Dijkstra() {
	fill(dis,dis+N,INF);
	memset(mark,0,sizeof(mark));
	dis[1]=0;//���Լ�
	mark[1]=1;
	
	int p=1;//ָ�¼ӵ�node
	for(int i=1; i<n; i++) { //n-1�Σ�ȷ��n-1��������· 
		for(int j=0; j<e[p].size(); j++) { //�����¼ӵĵ��all�ڱ�
			int t=e[p][j].next;
			if(mark[t]) continue;
			int c=e[p][j].cost;
			if(dis[t]==INF || dis[t]>dis[p]+c)//t�ڵ��в��ɴor��p��t����
				dis[t]=dis[p]+c;
		}
		int mi=INF;
		for(int j=1; j<=n; j++) { //ѡ��һ�����·��node
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
			t.next=a;//����ͼ����������Ҫ���
			e[b].push_back(t);
		}
		Dijkstra();
		printf("%d\n", dis[n]);
	}
	return 0;
}
