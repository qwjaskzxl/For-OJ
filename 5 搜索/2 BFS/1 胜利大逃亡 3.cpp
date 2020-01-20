#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=51;
int maze[N][N][N];//0��·��1��ǽ
int vis[N][N][N];
int a,b,c,ti;//a*b*c��maze��ti���޶�ʱ��
struct node {
	int x,y,z;
	int t;
} s,v; //�����������ṹ������� ���澭�����õ���û���ر��壬
	   //��˵�У��Ǿ���s����temp��v������ʾnext node����ʵ����һ��s��ʾ�����˶���
queue<node>q;
int go[6][3]= {0,0,1, 0,0,-1, 0,1,0, 0,-1,0, 1,0,0, -1,0,0}; //6������

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
			int nx=s.x+go[i][0];//0��ʼ���������� 
			int ny=s.y+go[i][1];
			int nz=s.z+go[i][2];
			if(nx<0 || ny<0 || nz<0 || nx>=a || ny>=b || nz>=c)
				continue;//����
			if(vis[nx][ny][nz]) continue;//�ѷ���
			if(maze[nx][ny][nz]==1) continue;//��ǽ

			vis[nx][ny][nz]=1;
			v.x=nx;
			v.y=ny;
			v.z=nz;
			v.t=s.t+1;
			q.push(v);
		}
	}
	return -1;//BFS���˶�ûreturn��˵��û��ȥ
}
int main() { //15:22->16:0?
	int T;
	cin>>T;
	while(T--) {
		memset(vis,0,sizeof(vis));//maze����init����Ϊinput�޶�����
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
