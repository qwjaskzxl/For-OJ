#include<iostream>
#include<map>//����ֱ����sort����
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e7+5;
int tree[N];//������ʾ���ϣ�ÿ��Ԫ�ص�ֵ�����ĸ��ڵ���
int sum[N];//��һ�������ڵ�Ԫ���� 

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
		fill(sum,sum+N,1);//��ʼ��Ϊ 1����4
		while(n--) {
			int a,b;
			scanf("%d%d", &a,&b);
			a=find_root(a);
			b=find_root(b);
			if(a!=b) {
				tree[a]=b;
				sum[b]+=sum[a];//b�Ǹ�����a�ļӵ� b�� 
			}
		}
//		sort(sum,sum+N);�����nlogn��������������һ��max��O(n)�Ϳ��԰� 
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
