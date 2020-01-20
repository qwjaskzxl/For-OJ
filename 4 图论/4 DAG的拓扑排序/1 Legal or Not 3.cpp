#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N=105;
vector<int>e[N];//�ڽ�����
queue<int>q;//�������Ϊ0��node
int inDegree[N];//ͳ��ÿ��node�����

int main() {
	int n,m;//��������ϵ��
	while(scanf("%d%d", &n,&m)!=EOF, n!=0) {
		for(int i=0;i<N;i++) e[i].clear();
		memset(inDegree,0,sizeof(inDegree));
		while(m--){
			int a,b;
			scanf("%d%d", &a,&b);
			inDegree[b]++;//���++ 
			e[a].push_back(b);
		}
		while(!q.empty()) q.pop();//queueû��clear 
		for(int i=0;i<n;i++){
			if(inDegree[i]==0) q.push(i);//���Ϊ0����� 
		}
		
		int cnt=0;
		while(!q.empty()){
			int p=q.front();//���Ϊ0��node p
			cnt++;
			q.pop();
			for(int i=0;i<e[p].size();i++){//����pָ���node 
				if(--inDegree[e[p][i]]==0) q.push(e[p][i]);
			}			
		}
		if(cnt==n) printf("YES\n");//all node�ܱ�ȷ����������˵���޻� 
		else printf("NO\n");
	}
	return 0;
}
