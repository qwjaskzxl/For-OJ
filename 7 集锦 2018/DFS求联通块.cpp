/*
输入一个m行n列的字符矩阵，只要有两个‘@’相邻就能组成一个联通块，
如下面的字符矩阵有2个联通块

****@
*@@*@
*@**@
@@@*@
@@**@

分析： 
将字符矩阵看作一个图，用DFS对图中的字符遍历，
从每个’@’出发，遍历’@’周围的字符。
每次访问时给该位置打上块标志，表示已访问，从而避免多次访问同一个位置。

*/

#include<bits/stdc++.h>
#define maxn 10
using namespace std;
int m,n;
char Map[maxn][maxn];
int vst[maxn][maxn]; 
int Next[8][2]={0,1,0,-1, 1,1,1,-1, 1,0,-1,0,-1,-1,-1,1};
void DFS(int x,int y,int index){
    int dr,dc;
    //超过边界，返回 
    if(x < 0 || x >= m || y < 0 || y >=n)//Map是从0开始的 
        return;
    //不是联通块的组成部分或已访问,返回
    if(Map[x][y] != '@' || vst[x][y] >0)
        return;
    //对符合条件的开始遍历
    vst[x][y] = index;
    for(int i=0;i<8;i++)
    {
    	int nx=x+Next[i][0];
    	int ny=y+Next[i][1];
    	DFS(nx,ny,index);
	}
//    for(dr = -1; dr <= 1; dr++)
//	{
//        for(dc = -1; dc <= 1; dc++)
//		{
//            if(dr != 0 || dc != 0)
//			{
//                DFS(x+dr,y+dc,index);
//            }
//        }
//    }
}
int main()
{
    int i,j;
    cin>>m>>n;
    for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
        cin>>Map[i][j];
  
    memset(vst,0,sizeof(vst));
    int cnt = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(Map[i][j] == '@' && vst[i][j] == 0){ //符合块条件且未访问过 
                //找到一个新的 
                DFS(i,j,++cnt); 
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
} 
