/* 
��Ŀ������
ͼ��https://blog.csdn.net/luoluozlb/article/details/51339264 
����0~9�����֡�Ҫ���������������ֲ������ڡ�
�����ҡ����¡��ԽǶ������ڣ�

һ���ж����ֿ��ܵ�����������
*/
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int a[10][10],vst[10][10];
int cnt=0;

int Next[4][2]={1,0,0,-1,0,1,-1,0};
void DFS(int x,int y)
{
	if(x==0||y==0||x>4||y>3||x==1&&y==1||x==4&&y==3)
	{
		cnt++;
		return ;
	}
	
	for(int i=0;i<4;i++)//����
	{
		int nx=x+Next[i][0];
		int ny=y+Next[i][1];
		if(vst[nx][ny]||nx==0||ny==0||nx>4||ny>3||nx==1&&ny==1||nx==4&&ny==3)
		for(int j=0;i<=9;j++)//������ 
		{
			
		}
	} 
}

int main()
{
	memset(vst,0,sizeof(vst));
	
}
