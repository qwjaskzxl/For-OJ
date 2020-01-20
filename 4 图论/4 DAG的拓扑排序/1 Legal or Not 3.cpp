#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N=105;
vector<int>e[N];//邻接链表
queue<int>q;//保存入度为0的node
int inDegree[N];//统计每个node的入度

int main() {
	int n,m;//人数，关系数
	while(scanf("%d%d", &n,&m)!=EOF, n!=0) {
		for(int i=0;i<N;i++) e[i].clear();
		memset(inDegree,0,sizeof(inDegree));
		while(m--){
			int a,b;
			scanf("%d%d", &a,&b);
			inDegree[b]++;//入度++ 
			e[a].push_back(b);
		}
		while(!q.empty()) q.pop();//queue没有clear 
		for(int i=0;i<n;i++){
			if(inDegree[i]==0) q.push(i);//入度为0的入队 
		}
		
		int cnt=0;
		while(!q.empty()){
			int p=q.front();//入度为0的node p
			cnt++;
			q.pop();
			for(int i=0;i<e[p].size();i++){//遍历p指向的node 
				if(--inDegree[e[p][i]]==0) q.push(e[p][i]);
			}			
		}
		if(cnt==n) printf("YES\n");//all node能被确定拓扑排序，说明无环 
		else printf("NO\n");
	}
	return 0;
}
