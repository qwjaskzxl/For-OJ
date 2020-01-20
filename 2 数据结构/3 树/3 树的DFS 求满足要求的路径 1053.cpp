#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=105;
const int M=1000000007;
const int INF=0x7fffffff;
int n,m,s;//node数，非叶node数，目标值
struct node {
	int w;//权重
	vector<int>child;
} nd[N];
int cmp(int a,int b) {
	return nd[a].w>nd[b].w;
}
vector<int>ans;
void DFS(int id,int cnt) {
	if(cnt==s && nd[id].child.size()==0) {
		for(int i=0; i<ans.size()-1; i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[ans.size()-1]);
		return ;
	}
	else if(cnt>s) return ;
	for(int i=0;i<nd[id].child.size();i++){
		int c=nd[id].child[i];
		ans.push_back(nd[c].w);//cout<<cnt+nd[c].w<<' ';
		DFS(nd[id].child[i], cnt+nd[c].w);
		ans.pop_back();
	}
}
int main() {//coding  15:25->15:56
	cin>>n>>m>>s;
	for(int i=0; i<n; i++)
		scanf("%d", &nd[i].w);
	for(int i=0,id,c; i<m; i++) {
		cin>>id>>c;
		for(int j=0,idc; j<c; j++) {
			cin>>idc;
			nd[id].child.push_back(idc);
		}
		sort(nd[id].child.begin(),nd[id].child.end(),cmp);//让child在vector中降序排序 
	}
	ans.push_back(nd[0].w);//注意先把root放进去 
	DFS(0,nd[0].w);
	return 0;
}
/*

*/
