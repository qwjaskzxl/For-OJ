/*��������n*m��С�ĵ�ͼ��������½�أ���"#"��ʾ���ͺ�����"."��ʾ����
����Ҫ�������ŵ�ͼ�ϵ����������
��֪��������½�ص���ͨ����ɣ�
��һ��½�ص��ϡ��¡����ң����ϣ����ϣ����£�����������½�أ��򹹳���ͨ�飬�Դ����ơ�
���⣬�������ϸ�������£�
1���������Χ����ȫ�Ǻ���
2�������ͨ�������������ڵ�ͼ�߽磬�����ͨ�鲻�ǵ��졣

��������:
��1��������������n��m�������ͼ�ĳ��Ϳ�
��2-n+1�У�ÿ������m���ַ����ַ�Ϊ"#"��ʾ½�أ�Ϊ"."��ʾ����
���ݱ�֤��0<n,m��200
�������:
���һ���������������������

ʾ��1
����
3 3
...
.#.
...
���
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

