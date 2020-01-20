#include<iostream>
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

int main() { //16:06->16:25
	int n,m;//������������
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
		for(int i=1; i<=n&&ok>=0; i++)//���롱��ôд�ɶ������� 
			if(tree[i]==-1) {
				ok--;//С��0˵��������root��˵������ͨ 
			}
		printf("%s\n",ok>=0?"YES":"NO");
	}
	return 0;
}
