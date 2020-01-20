#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
int tree[N];
struct Edge {
	int a,b;//名字就是一个字母，序号用 -'A'表示
	int cost;
	int ok;//是否已经建好
} e[N*N];
int cmp(Edge x, Edge y) {
	if(x.ok!=y.ok) return x.ok>y.ok;//修建好的优先！这个思路非常巧妙
	else return x.cost<y.cost;
}
int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);
		tree[x]=root;
		return root;
	}
}
int main() {
	int n;//城市数
	while(scanf("%d", &n)!=EOF, n!=0) {
		memset(tree,-1,sizeof(tree));
		int m=n*(n-1)/2;
		for(int i=0; i<m; i++) {
			scanf("%d%d%d%d", &e[i].a,&e[i].b,&e[i].cost,&e[i].ok);
		}
		sort(e,e+m,cmp);
		int ans=0;
		for(int i=0; i<m; i++) { //遍历每个edge
			int a=find_root(e[i].a);
			int b=find_root(e[i].b);
			if(a!=b) {//这就是合并操作，最后的结果一定是在给定数据内都连通。
				//因为这里给了每个点之间的关系，而有时候可能某两点之间压根没路，这样当然是无法连通了
				tree[a]=b;
				if(e[i].ok==0)
					ans+=e[i].cost;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
