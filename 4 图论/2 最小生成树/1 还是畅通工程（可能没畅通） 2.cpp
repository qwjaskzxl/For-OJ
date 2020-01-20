#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int tree[N];//记录node
struct Edge {
	int a,b;
	int cost;
} e[N]; //只是用于存储两node间的cost，而不一定真有这条edge！真正的edge本质在tree记录
int cmp(Edge a,Edge b) {
	return a.cost<b.cost;
}
int n,m;//道路数，村庄数

int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);
		tree[x]=root;
		return root;
	}
}
bool is_connected() { //判断图是否连通
	for(int i=1,ok=1; i<=m; i++) {
		if(tree[i]==-1) ok--;
		if(ok<0) return false;
	}
	return true;
}

int main() {
	while(scanf("%d%d", &n,&m)!=EOF, n!=0) {
		memset(tree,-1,sizeof(tree));
		for(int i=1; i<=n; i++)
			scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].cost);
		sort(e+1,e+1+n,cmp);
		int ans=0;
		for(int i=1; i<=n; i++) {
			int a=find_root(e[i].a);
			int b=find_root(e[i].b);
			if(a!=b) { //判断一个edge两段的node是否已经联通
				tree[a]=b;
				ans+=e[i].cost;
			}
		}
		if(is_connected()) printf("%d\n", ans);//刚开始这个函数忘记打括号了。。没有运行
		else printf("?\n");
	}
	return 0;
}
