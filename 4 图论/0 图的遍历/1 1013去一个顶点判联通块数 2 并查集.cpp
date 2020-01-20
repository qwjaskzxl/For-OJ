#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=1005;
vector<int>e[N];
int tree[N];//���鼯
int findRoot(int x) {
	if(tree[x]==-1) return x;//������-1
	else {
		int root=findRoot(tree[x]);
		tree[x]=root;
		return root;
	}
}
int n,m,k;//���У�·��query
/*
ע�⣺����Ҫ�ȴ�һ��edge��Ȼ������Ӧ��queryʱ����ͨ����
*/
int main() {
	cin>>n>>m>>k;
	while(m--) {
		int a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	while(k--) {
		int q,ans=-1;//query
		cin>>q;
		memset(tree,-1,sizeof(tree));
		for(int i=1; i<=n; i++) {
			for(int j=0; j<e[i].size(); j++) {
				if(i==q || e[i][j]==q) continue;
				int a=findRoot(i);
				int b=findRoot(e[i][j]);
				if(a!=b) tree[a]=b;
			}
		}
		for(int i=1; i<=n; i++) {
			if(i==q) continue;
			if(tree[i]==-1) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
