#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int a[62][1288][130];
int vis[62][1288][130];
int m,n,l,t;
struct node {
	int x,y,z;
	int cnt;
} s,v;
queue<node>q;
int go[6][3]= {0,0,1,0,0,-1,
               1,0,0,-1,0,0,
               0,1,0,0,-1,0
              };

int BFS(int x,int y,int z) {
	int ans=0;
	s.x=x;
	s.y=y;
	s.z=z;
	s.cnt=0;
	q.push(s);
	vis[x][y][z]=1;
	while(!q.empty()) {
		s=q.front();
//		cout<<s.x<<' '<<s.y<<' '<<s.z<<endl;
		ans++;
		q.pop();
		for(int i=0; i<6; i++) {
			int nx=s.x+go[i][0];
			int ny=s.y+go[i][1];
			int nz=s.z+go[i][2];
			if(vis[nx][ny][nz] || nx>l||ny>m||nz>n || nx<1||ny<1||nz<1) continue;
			if(a[nx][ny][nz]==1) {
				v.x=nx;
				v.y=ny;
				v.z=nz;
				v.cnt=s.cnt+1;
				q.push(v);
				vis[nx][ny][nz]=1;//忘记标记了，炸了内存 
			}
		}
	}
	if(ans>=t) return ans;
	else return 0;
}

int main() { //coding:19:40->20:40，还炸了内存 
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	cin>>m>>n>>l>>t;
	for(int i=1; i<=l; i++) //这是z轴吧？
		for(int j=1; j<=m; j++)
			for(int k=1; k<=n; k++)
				scanf("%d", &a[i][j][k]);
	int ans=0;	
	for(int i=1; i<=l; i++) //这是z轴吧？
		for(int j=1; j<=m; j++)
			for(int k=1; k<=n; k++)
				if(vis[i][j][k]==0&&a[i][j][k]==1)
					ans+=BFS(i,j,k);
	cout<<ans;
	return 0;
}
/*
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
*/

