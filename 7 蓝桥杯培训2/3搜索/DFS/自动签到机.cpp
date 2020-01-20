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
#define maxn 12
using namespace std;
int m,n;
char Map[maxn][maxn];
int vst[maxn][maxn]; 
int Next[8][2]={0,1,0,-1,1,0,-1,0};//注意！找外边的 斜着不能算联通 
void DFS(int x,int y,int index){
    int dr,dc;
    //超过边界，返回 
    if(x < 0 || x > m+1 || y < 0 || y > n+1)//Map是从0开始的 
        return;
    //不是联通块的组成部分或已访问,返回
    if(Map[x][y] != '_' || vst[x][y] >0)
        return;
    //对符合条件的开始遍历
    vst[x][y] = index;
    for(int i=0;i<4;i++)
    {
    	int nx=x+Next[i][0];
    	int ny=y+Next[i][1];
    	DFS(nx,ny,index);
	}
}
int main()
{	
    int i,j;
    int T=1;cin>>T;
    while(T--)
    {
	    m=n=10;
	    memset(Map,'_',sizeof(Map));
	    memset(vst,0,sizeof(vst));
	    for(i = 1; i <= m; i++)
	    for(j = 1; j <= n; j++)
	        cin>>Map[i][j];
	  	  
	    int cnt = 0;
	    for(i = 0; i <= m+1; i++)	//在大外圈找 
	    for(j = 0; j <= n+1; j++)		
	        if(Map[i][j] == '_' && vst[i][j] == 0) //符合块条件且未访问过                
	    		DFS(i,j,++cnt);//找到新的继续DFS 
				               
	    //cout<<cnt<<endl;
	    switch(cnt)
	    {
	    	case 1:cout<<1<<endl;break;
	    	case 2:cout<<0<<endl;break;
	    	case 3:cout<<8<<endl;break;
		}
	}
    return 0;
} 
