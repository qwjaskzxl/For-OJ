/*
����ͼ��ʾ������,
����5->7->8->3->7��˳��,���õ����ֵ30

���룺
��һ��������N(100>=N>1),��ʾɽ�ĸ߶ȡ�
��������N�зǸ�����,��i����i������(1<=i<=N),��
ʾɽ�ĵ�i���ϴ�����ÿ��·�ϵ��鱦��Ŀ
�����
һ������,��ʾ��ɽ�׵�ɽ�������ܵõ����鱦�������Ŀ.

��������
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
�������
30
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[105][105];
int d[105][105];
int DP(int x,int y)
{
	if(x==n)
	{
		return a[x][y];
	}
	else 
	return a[x][y]+max(DP(x+1,y),DP(x+1,y+1));
}
//DP2Ϊ���仯���� 
int DP2(int x,int y)
{
	if(d[x][y]>=0)
	{
		return d[x][y];
	}
	if(x==n)
	{
		return d[x][y]=a[x][y];
	}
	else 
	return d[x][y]=a[x][y]+max(DP2(x+1,y),DP2(x+1,y+1));
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		cin>>a[i][j];
	}	
	memset(d,-1,sizeof(d));
	
	cout<<DP2(1,1);
}
