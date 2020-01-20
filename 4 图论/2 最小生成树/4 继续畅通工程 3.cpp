#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
int tree[N];
struct Edge {
	int a,b;//���־���һ����ĸ������� -'A'��ʾ
	int cost;
	int ok;//�Ƿ��Ѿ�����
} e[N*N];
int cmp(Edge x, Edge y) {
	if(x.ok!=y.ok) return x.ok>y.ok;//�޽��õ����ȣ����˼·�ǳ�����
	else return x.cost<y.cost;
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
	int n;//������
	while(scanf("%d", &n)!=EOF, n!=0) {
		memset(tree,-1,sizeof(tree));
		int m=n*(n-1)/2;
		for(int i=0; i<m; i++) {
			scanf("%d%d%d%d", &e[i].a,&e[i].b,&e[i].cost,&e[i].ok);
		}
		sort(e,e+m,cmp);
		int ans=0;
		for(int i=0; i<m; i++) { //����ÿ��edge
			int a=find_root(e[i].a);
			int b=find_root(e[i].b);
			if(a!=b) {//����Ǻϲ����������Ľ��һ�����ڸ��������ڶ���ͨ��
				//��Ϊ�������ÿ����֮��Ĺ�ϵ������ʱ�����ĳ����֮��ѹ��û·��������Ȼ���޷���ͨ��
				tree[a]=b;
				if(e[i].ok==0)
					ans+=e[i].cost;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
