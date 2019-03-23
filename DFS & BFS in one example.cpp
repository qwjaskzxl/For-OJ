#include<bits/stdc++.h>
#include<queue>
using namespace std;
char Map[100][100];
int vst[100][100];
int a,b,n,cnt=0;
int Min=99999;
int Next[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int DFS(int x,int y,int cnt)//cnt也就是step记录步数 
{
	if(Map[x][y]=='B')
	{
		if(cnt<Min) Min=cnt;
//		cout<<cnt<<endl;
		return 0;
	}
	
	int nx,ny;
	for(int i=0;i<=3;i++)
	{
		nx=x+Next[i][0];
		ny=y+Next[i][1];
		if(vst[nx][ny] || Map[nx][ny]=='A' || Map[nx][ny]==Map[x][y] || Map[nx][ny]=='0')			
			continue;	//换方向 
		
		vst[nx][ny]=1;		
		DFS(nx,ny,cnt+1);
		vst[nx][ny]=0;
	}	
}

struct node{
	int x,y;
	int step;
}s,v;
queue<node>q;
int BFS() //不能广搜啊。。。 
{
	s.x=a; s.y=b; s.step=0;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		if(Map[s.x][s.y]=='B')
		{
			cout<<s.step;
			return 0;
		}
		for(int i=0;i<4;i++)
		{
//			cout<<s.step<<endl;
			v.x=s.x+Next[i][0];
			v.y=s.y+Next[i][1];
			if( Map[v.x][v.y]==Map[v.x][v.y] ||
				vst[v.x][v.y] ||
				Map[v.x][v.y]=='A' ||
				Map[v.x][v.y]=='0' )
				continue;
			vst[v.x][v.y]=1;
			v.step=s.step+1;
			q.push(v);
		}
		q.pop();
	}
}
int main()
{
	cin>>n;	
	memset(Map,'0',sizeof(Map));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>Map[i][j];
			if(Map[i][j]=='A'){a=i;b=j;}
		}	
	
	memset(vst,0,sizeof(vst));			
//	DFS(a,b,0);
//	if(Min==99999) cout<<-1;//cnt不变是因为DFS函数结束了，也就是搜完啦 
//	else cout<<Min;
	BFS();
} 
