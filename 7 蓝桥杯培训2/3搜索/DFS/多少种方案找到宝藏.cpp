#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int Mod=1000000007;
int n,m,k,cnt=0;
int Map[52][52],vst[52][52];
vector<int>v; 

void DFS(int x,int y,int Max,int N)
{
	if((x>n||y>m)&&x+y!=n+m+1 || x+y!=n+m+1&&N==k) 
//if((x>n||y>m)&&(x+y!=m+n+1)||N>k)
return;//没在终点就：出去了或者拿 k个了

	if(x+y==n+m+1&&N==k)	//这样一定到边界了 
	{
		cnt++; cnt%=Mod;
		return ;
	}
//	int t=1;
//	for(int i=0;i<v.size();i++)
//		if(Map[x][y]<=v[i] && N!=0) t=0;
	if(Map[x][y]>Max)
	{	
		vst[x][y]=1; 
//		v.push_back(Map[x][y]);
		DFS(x+1,y,Map[x][y],N+1);
		DFS(x,y+1,Map[x][y],N+1);		
	}
	vst[x][y]=0; 
	DFS(x+1,y,Max,N);
	DFS(x,y+1,Max,N);
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>Map[i][j];
	memset(vst,0,sizeof(vst));
	DFS(1,1,-1,0);
	cout<<cnt/2;
}
