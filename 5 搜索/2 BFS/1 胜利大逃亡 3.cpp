#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=51;
int maze[N][N][N];//0是路，1是墙
int vis[N][N][N];
int a,b,c,ti;//a*b*c的maze，ti是限定时间
struct node {
	int x,y,z;
	int t;
} s,v; //不过是两个结构体变量， 后面经常会用到，没有特别含义，
	   //若说有，那就是s更像temp，v用来表示next node（其实就是一个s表示不下了而已
queue<node>q;
int go[6][3]= {0,0,1, 0,0,-1, 0,1,0, 0,-1,0, 1,0,0, -1,0,0}; //6个方向

int BFS() {
	vis[0][0][0]=1;
	s.x=s.y=s.z=s.t=0;
	q.push(s);
	while(!q.empty()) {
		s=q.front();
		if(s.x==a-1 && s.y==b-1 && s.z==c-1)
			return s.t;
		q.pop();
		for(int i=0; i<6; i++) {
			int nx=s.x+go[i][0];//0开始！！整错了 
			int ny=s.y+go[i][1];
			int nz=s.z+go[i][2];
			if(nx<0 || ny<0 || nz<0 || nx>=a || ny>=b || nz>=c)
				continue;//出界
			if(vis[nx][ny][nz]) continue;//已访问
			if(maze[nx][ny][nz]==1) continue;//是墙

			vis[nx][ny][nz]=1;
			v.x=nx;
			v.y=ny;
			v.z=nz;
			v.t=s.t+1;
			q.push(v);
		}
	}
	return -1;//BFS完了都没return，说明没出去
}
int main() { //15:22->16:0?
	int T;
	cin>>T;
	while(T--) {
		memset(vis,0,sizeof(vis));//maze不用init，因为input限定死了
		while(!q.empty()) q.pop();
		scanf("%d%d%d%d", &a,&b,&c,&ti);
		for(int i=0; i<a; i++)
			for(int j=0; j<b; j++)
				for(int k=0; k<c; k++) {
					scanf("%d", &maze[i][j][k]);
				}
		int ans=BFS();
		printf("%d\n", ans<=ti?ans:-1);
	}
	return 0;
}
