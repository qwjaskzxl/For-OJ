#include<string.h>
#include<iostream> 
using namespace std;
char map[12][12];//�´α���������� 
int cnt=0,vst[12][12];
int DFS(int x,int y)//ע�����飬x���� y���� 
{
	if(x==0||y==0||x==11||y==11)
	{		
		cnt++;
//		cout<<x<<' '<<y<<' '<<cnt<<endl;
		return 0;
	}
	if(vst[x][y]) return 0;
	vst[x][y]=1;

	if(map[x][y]=='U') DFS(x-1,y);
	if(map[x][y]=='D') DFS(x+1,y);
	if(map[x][y]=='L') DFS(x,y-1);
	if(map[x][y]=='R') DFS(x,y+1);
}
 
int main()
{
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			cin>>map[i][j];//��������룬����֪��������ԭ�㣬���Ͻǲ���0,0 
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
		{
			memset(vst,0,sizeof(vst));
			DFS(i,j);
		}	
	cout<<cnt; 
}
