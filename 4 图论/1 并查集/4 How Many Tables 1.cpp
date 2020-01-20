#include<iostream>
#include<cstring>
using namespace std;
const int N=1005;
int tree[N];//������ʾ���ϣ�ÿ��Ԫ�ص�ֵ�����ĸ��ڵ���
int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);
		tree[x]=root;
		return root;
	}
}
int main() { //16:32->16:42
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(tree,-1,sizeof(tree));
		int n,m;//��������ϵ��
		scanf("%d%d", &n,&m);
		while(m--) {
			int a,b;
			scanf("%d%d", &a,&b);
			a=find_root(a);
			b=find_root(b);
			if(a!=b) tree[a]=b;
		}
		int sum=0;
		for(int i=1; i<=n; i++) {
			if(tree[i]==-1) sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
