#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int tree[N];//��¼node
struct Edge {
	int a,b;
	int cost;
} e[N]; //ֻ�����ڴ洢��node���cost������һ����������edge��������edge������tree��¼
int cmp(Edge a,Edge b) {
	return a.cost<b.cost;
}
int n,m;//��·������ׯ��

int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);
		tree[x]=root;
		return root;
	}
}
bool is_connected() { //�ж�ͼ�Ƿ���ͨ
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
			if(a!=b) { //�ж�һ��edge���ε�node�Ƿ��Ѿ���ͨ
				tree[a]=b;
				ans+=e[i].cost;
			}
		}
		if(is_connected()) printf("%d\n", ans);//�տ�ʼ����������Ǵ������ˡ���û������
		else printf("?\n");
	}
	return 0;
}
