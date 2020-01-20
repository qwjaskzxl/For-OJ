#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10;
char maze[N][N];
int vis[N][N];
int m,n,t,ans;
int sx,sy,dx,dy;//开始位置和门的位置
int go[4][2]= {0,1,1,0,0,-1,-1,0};

void DFS(int x,int y,int step) {
	if(step==t && maze[x][y]=='D') {
		ans=1;
		return ;
	} else if(step>t || ans)
		return ;
	for(int i=0; i<4; i++) {
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<0||ny<0||nx>=m||ny>=n) continue;
		if(!vis[nx][ny] && (maze[nx][ny]=='.'||maze[nx][ny]=='D')) {//别忘了D是终点，当然可以走
			vis[nx][ny]=1;
//			cout<<step<<' '<<x<<y<<endl;
			DFS(nx,ny,step+1);
			vis[nx][ny]=0;
		}
	}
}
int main() {
	while(scanf("%d%d%d", &m,&n,&t)!=EOF) {
		if(!m&&!n&&!t) break;
		memset(vis,0,sizeof(vis));
		ans=0;
		for(int i=0; i<m; i++)
			scanf("%s", &maze[i]);
		for(int i=0,ok_s=0,ok_d=0; i<m&&(!ok_s||!ok_d); i++)
			for(int j=0; j<n&&(!ok_s||!ok_d); j++) {
				if(maze[i][j]=='S') {
					sx=i;
					sy=j;
					ok_s=1;
				} 
				else if(maze[i][j]=='D') {
					dx=i;
					dy=j;
					ok_d=1;
				}
			}
		//华丽的prune：奇偶性同，但t为奇数，不行；反之也不行 
//		if((sx+sy)&1==(dx+dy)&1 && t&1==1 || (sx+sy)&1!=(dx+dy)&1 && t&1==0) {
		if(((dx+dy+sx+sy)&1) != (t&1)){
//			cout<<((dx+dy)&1)<<' '<<((sx+sy+t)&1)<<' '<<t<<endl;
			printf("NO\n");
		} 
		else {
			DFS(sx,sy,0);
			printf("%s\n",ans?"YES":"NO");
		}
	}
	return 0;
}
