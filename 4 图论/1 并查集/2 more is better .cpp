#include<iostream>
#include<map>//不能直接用sort排序
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e7+5;
int tree[N];//用树表示集合，每个元素的值是它的父节点编号
int sum[N];

int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);
		tree[x]=root;
		return root;
	}
}
int main() {
	int n;
	while(scanf("%d", &n)!=EOF) {
		memset(tree,-1,sizeof(tree));
		memset(sum,0,sizeof(sum));
		while(n--) {
			int a,b;
			scanf("%d%d", &a,&b);
			a=find_root(a);
			b=find_root(b);
			if(a!=b) tree[a]=b;
		}
		for(int i=0; i<N; i++) {
			if(tree[i]!=-1) {
				sum[find_root(tree[i])]++;
			}
		}
		sort(sum,sum+N);
		printf("%d\n", sum[N-1]+1);
	}
	return 0;
}
