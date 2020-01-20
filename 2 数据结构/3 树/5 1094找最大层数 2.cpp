#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
const int N=105;
struct node {
	int layer=1;
	vector<int>child;
} tree[N];
int n,m;

void BFS(int root) {
	queue<int>q;
	q.push(root);
	while(!q.empty()) {
		int t=q.front();
		q.pop();
		int chN=tree[t].child.size();
		for(int i=0; i<chN; i++) {
			int ch=tree[t].child[i];
			tree[ch].layer=tree[t].layer+1;
			q.push(ch);
		}
	}
}

int main() {
	cin>>n>>m;
	while(m--) {
		int id,k,t;
		cin>>id>>k;
		while(k--) {
			cin>>t;
			tree[id].child.push_back(t);
		}
	}
	BFS(1);
	int cnt[N]={0};
	for(int i=1;i<=n;i++){
		cnt[tree[i].layer]++;
	}
	int maxN=-1,maxL;
	for(int i=1;i<=n;i++){
		if(maxN<cnt[i]){
			maxN=cnt[i];
			maxL=i;
		}
	}
	cout<<maxN<<' '<<maxL;
	return 0;
}
