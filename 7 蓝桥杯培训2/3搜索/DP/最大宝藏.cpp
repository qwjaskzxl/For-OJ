/*
在下图所示例子中,
按照5->7->8->3->7的顺序,将得到最大值30

输入：
第一行正整数N(100>=N>1),表示山的高度。
接下来有N行非负整数,第i行有i个整数(1<=i<=N),表
示山的第i层上从左到右每条路上的珠宝数目
输出：
一个整数,表示从山底到山顶的所能得到的珠宝的最大数目.

样例输入
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
样例输出
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
//DP2为记忆化搜索 
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
