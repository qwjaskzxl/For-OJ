#include<bits/stdc++.h> 
#include<queue>
using namespace std;
int Map[1000][1000],n,m;//��ͼ 
int vst[1000][1000];

struct node{
	int x,y,step;
	string path;
}s,v;//s��s���׽ڵ㡣v���ӽڵ㣬����һ������ 

queue<node>q;

int Next[4][2]={1,0,0,-1,0,1,-1,0};//Ҫ�ͷ����Ӧ��
char dic[5]={"DLRU"};
//��Ҫ�ֵ�����������Ⱥ������˳���Ϊ�ֵ����OK

int BFS()
{	
	s.x=s.y=1;//���λ�� 
	s.step=0;s.path="";
	q.push(s);
	while(!q.empty())
	{
		s=q.front();//ÿ�ζ�Ҫȡ��Ԫ�أ�����һ�α���ʼ������ 
		if(s.x==n&&s.y==m)
		{			
			cout<<s.step<<endl<<s.path;			
			break;
		}		
		for(int k=0;k<=3;k++)
		{
			v.x=s.x+Next[k][0];
			v.y=s.y+Next[k][1];
			if(vst[v.x][v.y]||v.x<1||v.x>n||v.y<1||v.y>m||Map[v.x][v.y]=='1') 
				continue;
			vst[v.x][v.y]=1;
			v.step=s.step+1;
			v.path=s.path+dic[k];
			q.push(v);//ÿ��OK�ķ������ 
		}
		q.pop();
	}
}

int main()
{	
	cin>>n>>m;
	getchar();
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
			Map[i][j]=getchar();
		getchar();
	}
	for(int j=1;j<=m;j++)	
		Map[n][j]=getchar();
	
	memset(vst,0,sizeof(vst));	
	BFS();
	return 0;
}
