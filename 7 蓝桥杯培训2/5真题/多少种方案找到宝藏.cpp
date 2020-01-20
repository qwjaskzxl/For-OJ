/*题目描述：
    X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。

    地宫的入口在左上角，出口在右下角。

    小明被带到地宫的入口，国王要求他只能向右或向下行走。

    走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。

    当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。

    请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。

输入：
    输入一行3个整数，用空格分开：n m k (1<=n,m<=50, 1<=k<=12)

    接下来有 n 行数据，每行有 m 个整数 Ci (0<=Ci<=12)代表这个格子上的宝物的价值

输出：
    要求输出一个整数，表示正好取k个宝贝的行动方案数。该数字可能很大，输出它对 1000000007 取模的结果。

样例输入
2 2 2
1 2
2 1
样例输出
2
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int Mod=1000000007;
int n,m,k,cnt=0;
int Map[52][52],vst[52][52];
vector<int>v; 

void DFS(int x,int y,int Max,int N)
{
	if((x>n||y>m)&&x+y!=n+m+1 || x+y!=n+m+1&&N==k) 
//if((x>n||y>m)&&(x+y!=m+n+1)||N>k)
return;//没在终点就：出去了或者拿 k个了

	if(x+y==n+m+1&&N==k)	//这样一定到边界了 
	{
		cnt++; cnt%=Mod;
		return ;
	}
//	int t=1;
//	for(int i=0;i<v.size();i++)
//		if(Map[x][y]<=v[i] && N!=0) t=0;
	if(Map[x][y]>Max)
	{	
		vst[x][y]=1; 
//		v.push_back(Map[x][y]);
		DFS(x+1,y,Map[x][y],N+1);
		DFS(x,y+1,Map[x][y],N+1);		
	}
	vst[x][y]=0; 
	DFS(x+1,y,Max,N);
	DFS(x,y+1,Max,N);
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>Map[i][j];
	memset(vst,0,sizeof(vst));
	DFS(1,1,-1,0);
	cout<<cnt/2;
}
