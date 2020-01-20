#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=101;
char maze[N][N];
int vis[N][N];
int m,n;

struct node {//BFSҲOK�� 
	int x,y,z;
	int t;
} s,v;
int go[8][2]= {0,1,1,0,0,-1,-1,0,
               1,1,-1,-1,-1,1,1,-1
              };//8����
int DFS(int x,int y) {
	for(int i=0; i<8; i++) {
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<0||ny<0||nx>=m||ny>=n) continue;
		if(!vis[nx][ny] && maze[nx][ny]=='@') {
			vis[nx][ny]=1;
			DFS(nx,ny);
//			vis[nx][ny]=0;//��Ҫ���ݣ����������ꡣ����·�ڵ����⣬��ʵ�ڷ����forѭ��������ˣ�ֻҪһ��·DFS�ߵ��׾�����
		}
	}
}
int main() {

	while(scanf("%d%d", &m,&n)!=EOF, m!=0) {
		memset(vis,0,sizeof(vis));
		for(int i=0; i<m; i++)
			scanf("%s", &maze[i]);
		int cnt=0;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) {
				if(!vis[i][j] && maze[i][j]=='@') {
					DFS(i,j);//����DFS��Ŀ�ľ��ǰ���ͨ�ı�����
					cnt++;
				}
			}
		cout<<cnt<<endl;
	}
	return 0;
}
