#include<iostream>
#include<vector>
using namespace std;
const int N=100;
struct node {
	int nextnode;//��һ���ڵ���
	int cost;
};
vector<node>Adj[N];//һ��Adjvex[i]��һ�����������飬��ʾһ��node

void graph_clear() {
	for(int i=0; i<N; i++)
		Adj[i].clear();
}
void init() {//�Ƚ�ͼ 
	node t;
	for(int i=0; i<N; i++) {
		t.nextnode=3;
		t.cost=48;
		Adj[i].push_back(t);
	}
}
void traverse() {//����
	for(int i=0; i<N; i++) {
		for(int j=0; j<Adj[i].size(); j++) { //һ��Adj[i]��һ������
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
