#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N=505;
vector<int>e[N];//�ڽ�����
priority_queue<int,vector<int>,greater<int>>q;//�������Ϊ0��node
int inDegree[N];//ͳ��ÿ��node�����
int n,m;//����������ϵ��
vector<int>ans;

int main() {
	while(scanf("%d%d", &n,&m)!=EOF) {
		if(!n&&!m) break;
		memset(inDegree,0,sizeof(inDegree));		
		for(int i=0;i<N;i++) e[i].clear();
		while(m--) {
			int a,b;
			scanf("%d%d", &a,&b);
			inDegree[b]++;
			e[a].push_back(b);//Ҫ����ͬ�ɼ��ģ����С������ 
		}
		while(!q.empty()) q.pop();
		ans.clear();
		
		for(int i=1; i<=n; i++) {
			if(inDegree[i]==0) q.push(i);
		}
		while(!q.empty()) {
			int p=q.top();
			ans.push_back(p);
			q.pop();
			for(int i=0; i<e[p].size(); i++) {
				if(--inDegree[e[p][i]]==0)
					q.push(e[p][i]);
			}
		}
		for(int i=0; i<ans.size()-1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[ans.size()-1]);
	}
	return 0;
}
