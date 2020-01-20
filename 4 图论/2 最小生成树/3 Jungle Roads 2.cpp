#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=30;
int tree[N];
struct Edge {
	char a,b;//名字就是一个字母，序号用 -'A'表示 
	int cost;
}e[N*N];
int cmp(Edge x, Edge y){
	return x.cost<y.cost;
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
	int num;//城市数
	while(scanf("%d", &num)!=EOF, num!=0){
		memset(tree,-1,sizeof(tree));
		int e_n=0, n;//边数，一个node连接的node数 
		char c1, c2;
		while(--num){			
			scanf("\n%c%d", &c1,&n);
//			cin>>c1>>n;//！错误原因是，scanf是可以吃空格的。。。 
			int co;//cost
			while(n--){				
				e[e_n].a=c1;
				scanf(" %c%d", &c2,&co);				
//				cin>>c2>>co;
				e[e_n].b=c2;
				e[e_n++].cost=co;
			}			
		}
		sort(e,e+e_n,cmp);
		int ans=0;
		
		for(int i=0;i<e_n;i++){//遍历每个edge 
			int a=find_root(e[i].a-'A');
			int b=find_root(e[i].b-'A');
			if(a!=b){
				tree[a]=b;
				ans+=e[i].cost;
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}
