#include<bits/stdc++.h>
using namespace std;

//int n,a[10],vst[10];
//int DFS0(int step)
//{
//	if(step==n+1)
//	{
//		for(int i=1;i<=n;i++) 
//			cout<<a[i];
//		cout<<endl;
//		return 0;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(!vst[i])//û���� 
//		{
//			vst[i]=1;//�����д�������ԣ�����Ȥ 
//			a[step]=i;//����i���� 
//			DFS(step+1); 
//			vst[i]=0;//�����ó��� 
//		}
//	}
//	return 0;//������ʵ�Ǳ�ʾ ��������������main���return 0 
//}
int n=0,vst[10][10];
int DFS(int x,int y)
{
	if(x==0||y==0||x==6||y==6)
	{
		n++;
		return 0;
	}
	int next[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	int nx,ny;
	for(int i=0;i<4;i++)
	{
		nx=x+next[i][0];
		ny=y+next[i][1];
		if(vst[nx][ny]) continue; //���ʹ��ˣ��ͽ�����һ������ 
		vst[nx][ny]=1;
		vst[6-nx][6-ny]=1;//���ĶԳƵ��Ǹ���Ҳһ����� 
		DFS(nx,ny);
		vst[nx][ny]=0;//�ջ� 
		vst[6-nx][6-ny]=0;
	}
}
int main()
{
	memset(vst,0,sizeof(vst));
	vst[3][3]=1;
	DFS(3,3);
	cout<<n/4; //��Ϊ���ĶԳ� 
}
