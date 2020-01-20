#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=1005;
int tree[N];//������ʾ���ϣ�ÿ��Ԫ�ص�ֵ�����ĸ��ڵ���

int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);//�ݹ��Ҹ�
		tree[x]=root;//·��ѹ�� 
		return root;
	}
}
int find_root2(int x) {
	int root, t=x;
	while(tree[x]!=-1)
		x=tree[x];
	root=x;
	
	x=t;//��ȥ����·��ѹ�� 
	while(tree[x]!=-1){
		t=tree[x];
		tree[x]=root;
		x=t;
	}
	return root;
}

int main() {
	int n,m;
	while(scanf("%d", &n)!=EOF, n!=0) {
		memset(tree,-1,sizeof(tree));
		scanf("%d", &m);
		while(m--) {
			int a,b;
			scanf("%d%d", &a,&b);
			a=find_root2(a);
			b=find_root2(b);
			if(a!=b) tree[a]=b;
		}
		int ans=0;
		for(int i=1; i<=n; i++) { //����ÿ�����������-1��˵����һ������ע�����Ǵ�1��ʼ�� 
//			cout<<tree[i]<<' ';
			if(tree[i]==-1) ans++;
		}
		printf("%d\n", ans-1);
	}
	return 0;
}

