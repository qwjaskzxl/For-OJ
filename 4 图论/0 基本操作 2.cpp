#include<iostream>
#include<vector>
using namespace std;
const int N=100;
struct node {
	int nextnode;//下一个节点编号
	int cost;
};
vector<node>Adj[N];//一个Adjvex[i]是一个不定长数组，表示一个node

void graph_clear() {
	for(int i=0; i<N; i++)
		Adj[i].clear();
}
void init() {//先建图 
	node t;
	for(int i=0; i<N; i++) {
		t.nextnode=3;
		t.cost=48;
		Adj[i].push_back(t);
	}
}
void traverse() {//遍历
	for(int i=0; i<N; i++) {
		for(int j=0; j<Adj[i].size(); j++) { //一个Adj[i]是一个顶点
			printf("%d ", Adj[i][j].nextnode);
			printf("%d ", Adj[i][j].cost);
		}
	}
}
int main() {
	graph_clear();
	init();
	traverse();
	return 0;
}
