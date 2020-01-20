#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_map>
#include<map>
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=1000000007;
const int INF=0x7fffffff;
int n,m;

//struct node {
//	int next;
//	int cost;
//} v;
//vector<node>e[N];
int dis[N];
int vis[N];
//set<int>st[N];
//set<int>::iterator it;
struct node {
	int next;
	int cost;
};
vector<node>e[N];
int vis[N];
int dis[N];
//int a[N],h[N]= {0};
//unordered_map<int,int>mp;
//unordered_map<int,int>::iterator it;
void D(int x){
	fill(dis,dis+N,INF);
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	vis[x]=1;
	int p=x;
	for(int i=1;i<n;i++){
		for(int j=0;j<e[i].size();j++){
			int t=e[i][j].next;
			if(vis[t]) continue;
			int c=e[i][j].cost;
			if(dis[t]==INF || dis[t]>dis[p]+c)
				xxx
			
		}
		
	}
}
int main() {
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b>>c;
		node t;
		t.cost=c;
		t.next=b;
		e[a].push_back(b);
		t.next=a;
		e[b].push_back(a);
	}
	D(0);
	return 0;
}
/*
2329
ans:17137
*/
