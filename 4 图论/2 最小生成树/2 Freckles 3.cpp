#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;
int tree[N];//记录node
struct Edge {
	int a,b;
	double cost;
} e[N*N/2];
bool cmp(Edge x,Edge y) {
	if(x.cost<y.cost && fabs(x.cost-y.cost)>1e-6)
		return true;
	else return false;
//	return x.cost<y.cost;
}
struct Node {
	double x,y;
	double get_dis(Node A) {
		return sqrt((x-A.x)*(x-A.x)+(y-A.y)*(y-A.y));
	}
} node[N];

int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);
		tree[x]=root;
		return root;
	}
}

int main() { //11:40->12:50
	int n;
	while(scanf("%d", &n)!=EOF, n!=0) {
		memset(tree,-1,sizeof(tree));
		for(int i=1; i<=n; i++)
			scanf("%lf%lf", &node[i].x,&node[i].y);
		int e_n=0;//边数，最后是n*(n-1)/2
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				e[e_n].a=i;
				e[e_n].b=j;
				e[e_n++].cost=node[i].get_dis(node[j]);
			}
		}
		double ans=0;
		sort(e,e+e_n,cmp);
		for(int i=0; i<e_n; i++) { //遍历每个edge，这里e从0开始，因为0/1无所谓
			int a=find_root(e[i].a);
			int b=find_root(e[i].b);
			if(a!=b) {
				tree[a]=b;
				ans+=e[i].cost;
//				printf("%.2lf\n", ans);
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
