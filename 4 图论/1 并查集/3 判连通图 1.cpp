#include<iostream>
#include<cstring>
using namespace std;
const int N=1005;
int tree[N];//用树表示集合，每个元素的值是它的父节点编号

int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);//递归找根
		tree[x]=root;//路径压缩
		return root;
	}
}

int main() { //16:06->16:25
	int n,m;//顶点数，边数
	while(scanf("%d%d", &n,&m)!=EOF, n!=0) {
		memset(tree,-1,sizeof(tree));
		while(m--) {
			int a,b;
			scanf("%d%d", &a,&b);
			a=find_root(a);
			b=find_root(b);
			if(a!=b) tree[a]=b;
		}
		int ok=1;
		for(int i=1; i<=n&&ok>=0; i++)//“与”怎么写成逗号了呢 
			if(tree[i]==-1) {
				ok--;//小于0说明有两个root，说明不连通 
			}
		printf("%s\n",ok>=0?"YES":"NO");
	}
	return 0;
}
