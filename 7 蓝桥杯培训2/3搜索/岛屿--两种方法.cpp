/*现在有张n*m大小的地图，标明了陆地（用"#"表示）和海洋（用"."表示），
现在要计算这张地图上岛屿的数量。
已知岛屿是由陆地的连通块组成，
即一块陆地的上、下、左、右，左上，右上，左下，右下有其他陆地，则构成连通块，以此类推。
此外，岛屿的详细定义如下：
1、岛屿的周围必须全是海洋。
2、如果连通块有任意区域在地图边界，则该连通块不是岛屿。

输入描述:
第1行输入两个整数n，m，代表地图的长和宽。
第2-n+1行，每行输入m个字符，字符为"#"表示陆地，为"."表示海洋。
数据保证：0<n,m≤200
输出描述:
输出一行整数，代表岛屿的数量。

示例1
输入
3 3
...
.#.
...
输出
1

*/

//DFS 
#include <bits/stdc++.h>

using namespace std;
const int maxn = 250;
char mp[250][250];
int vis[maxn][maxn]={0};
int dir[][2] ={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int n,m,flag=0;

void dfs(int x,int y)
{
    vis[x][y]=1;
     if(x==0||y==0||x==n-1||y==m-1)
           flag=1;
    for(int i=0;i<8;i++)
    {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(mp[tx][ty]=='#'&&tx>=0&&ty>=0)
        {
            mp[tx][ty]='.';
            dfs(tx,ty);
        }
    }
}
int main()
{
    int sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>mp[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='#')
            {
                flag=0;
                dfs(i,j);
                if(flag==0)
                    sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}


//BFS
#include<bits/stdc++.h>
using namespace std;
 
const int maxn=210;
 
char mp[maxn][maxn];
int vis[maxn][maxn];
const int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
 
int n,m,ans=0;

void bfs(int x,int y){
    if(mp[x][y]=='.'){
        vis[x][y]=2;
        return;
    }
    if(x==0||y==0||x==n-1||y==m-1){
        vis[x][y]=2;
      //  return;
    }
 
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int nowx=q.front().first;
        int nowy=q.front().second;
        if(nowx==0||nowy==0||nowx==n-1||nowy==m-1){
            vis[x][y]=2;
            //return;
        }
        q.pop();
        for(int i=0;i<8;++i){
            int x1=nowx+dir[i][0];
            int y1=nowy+dir[i][1];
            if(vis[x1][y1]==0&&mp[x1][y1]=='#'){
                vis[x1][y1]=1;
                q.push(make_pair(x1,y1));
            }
        }
    }
}
 
int main(){
    while(cin>>n>>m){
        memset(mp,0,sizeof(mp));
        memset(vis,false,sizeof(vis));
        ans=0;
        for(int i=0;i<n;++i)
            cin>>mp[i];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j]){
                    vis[i][j]=1;
                    bfs(i,j);
                    if(vis[i][j]==1){
 
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}

