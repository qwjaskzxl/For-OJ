//for every seniority level��Ҫ���ÿһ��Ҷ�ӽڵ���
#include<iostream>
#include<vector>
using namespace std;
const int N=105;
const int INF=0x7fffffff;
struct node {
	int data;//��¼�Լ���"node"��
	int layer;
	bool is_leaf;
//	vector<int>child;
} tree[N+5]; //����ȫ��hash�ˣ�eg tree[2].child��ʾ2�ĺ���
int ans[N+5];
int n,m;//��node,��Ҷ��node
int main() {
	cin>>n>>m;
	if(!n) return 0;
	for(int i=0; i<=N; i++) {
//			tree[i].child.clear();//ֻ��sizeΪ0���ռ�û�ͷš�����push_back����0��ʼ
		tree[i].layer=1;//������1
		tree[i].data=-1;//-1��ʾû���node
		tree[i].is_leaf=1;//��ʼ����Ҷ��
		ans[i]=0;
	}
	int layer_max=1;
	while(m--) {
		int nod,num;
		scanf("%d%d", &nod,&num);
		tree[nod].data=nod;
		tree[nod].is_leaf=0;
		for(int i=0; i<num; i++) {
			int t;
			scanf("%02d", &t);//���������λ
//				tree[nod].child.push_back(t);
			tree[t].data=t;
			tree[t].layer=tree[nod].layer+1;
			layer_max=max(layer_max, tree[t].layer);
		}
	}
	for(int i=1; i<=N; i++) {
		if(tree[i].data!=-1) {
			if(tree[i].is_leaf)
				ans[tree[i].layer]++;
		}
	}
	for(int i=1; i<layer_max; i++)
		cout<<ans[i]<<' ';
	cout<<ans[layer_max];
	return 0;
}
/*
72 34
01 5 26 4 66 11 31
26 5 57 60 14 17 25
04 2 69 20
57 4 35 13 16 45
66 3 41 36 56
69 3 37 2 7
41 3 58 38 65
35 4 46 68 59 61
11 2 15 44
14 1 18
37 1 6
13 2 30 67
30 1 34
46 3 42 27 62
18 2 72 71
42 3 29 51 53
31 1 12
12 2 54 63
15 5 5 52 47 21 64
17 4 8 23 19 49
08 1 24
23 1 9
52 2 39 3
24 1 48
48 1 10
54 1 70
71 1 55
06 1 43
64 1 33
39 1 50
70 1 22
20 1 40
25 1 32
40 1 28

0 0 4 14 9 7 4
*/
