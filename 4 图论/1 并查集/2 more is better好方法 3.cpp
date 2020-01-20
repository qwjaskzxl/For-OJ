#include<iostream>
#include<map>//不能直接用sort排序
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e7+5;
int tree[N];//用树表示集合，每个元素的值是它的父节点编号
int sum[N];//存一个集合内的元素数 

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
		fill(sum,sum+N,1);//初始化为 1个人4
		while(n--) {
			int a,b;
			scanf("%d%d", &a,&b);
			a=find_root(a);
			b=find_root(b);
			if(a!=b) {
				tree[a]=b;
				sum[b]+=sum[a];//b是根，故a的加到 b上 
			}
		}
//		sort(sum,sum+N);这个是nlogn。。明明就是找一个max，O(n)就可以啊 
//		printf("%d\n", sum[N-1]);
		int maxx=0;
		for(int i=0;i<N;i++){
			if(tree[i]==-1 && sum[i]>maxx)
				maxx=sum[i];				
		}
		printf("%d\n", maxx);
	}
	return 0;
}
