/*
题目描述：
X 国的一个网络使用若干条线路连接若干个节点。节点间的通信是双向的。
某重要数据包，为了安全起见，必须恰好被转发两次到达目的地。
该包可能在任意一个节点产生，我们需要知道该网络中一共有多少种不同的转发路径。
源地址和目标地址可以相同，但中间节点必须不同。 
如图这里写图片描述所示的网络。
1 -> 2 -> 3 -> 1 是允许的 1 -> 2 -> 1 -> 2 或者 1 -> 2 -> 3 -> 2 都是非法的。

输入：
输入数据的第一行为两个整数N M，分别表示节点个数和连接线路的条数(1<=N<=10000; 0<=M<=100000)。 接下去有M行，每行为两个整数 u 和 v，表示节点u 和 v 联通(1<=u,v<=N , u!=v)。 输入数据保证任意两点最多只有一条边连接，并且没有自己连自己的边，即不存在重边和自环。

输出：
输出一个整数，表示满足要求的路径条数。
*/
//#include<iostream>
//#include<cstdio>
//#include<vector>
//using namespace std;
//const int N=10009;
//vector<int> map[N];
//int n,m;
//int main()
//{
//    cin>>n>>m;
//    int i,j,k;
//    int ai,aj;
//    for(i=0;i<m;i++)
//    {
//        cin>>ai>>aj;
//        map[ai].push_back(aj);//双向连通
//        map[aj].push_back(ai);
//    }
//    int count=0 ;
//    for(i=1; i<=n; i++)//表示的i个节点
//    {
//        for(j=0; j< map[i].size(); j++)//第一个点
//        {
//            for(k=0; k<map[map[i][j]].size(); k++)//第2个点
//            {
//                if(map[map[i][j]][k]!=i)//第三个点不等于第一个点，不构成回路，则继续寻找第四个点
//                    {
//                       int dk=map[map[i][j]][k];//即  为第三个点
//                       for(int d=0; d<map[dk].size(); d++)//循环找第四个点，且不等于第二个点；正好转两次2和3第四次终结
//                       {
//                            if( map[i][j]!= map[dk][d] )
//                            {
//                                count++;
//                            }
//                       }
//                    }
//            }
//        }
//    }
//    cout<<count<<endl;
//    return 0;
//}
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<string.h>  
#include<vector>  
using namespace std;  
struct st  
{  
    vector<int> arr;  
}map[10001];  
int n,m,b[5],cnt=0;  
  
void dfs(int x, int num)//x为找到 的路数 ，num是出发点，也是下次要走的点    
{  
    int i,j,k;  
    if (x > 4 )  
    {  
        if (b[2]!=b[3] && b[2]!=b[1] &&b[2]!=b[4] && b[3]!=b[1] && b[3]!=b[4])  
        cnt++;  
        return ;  
    }  
    for (i=0; i<map[num].arr.size(); i++)//缩减不必要的循环  
    {  
        b[x] = map[num].arr[i];  
        dfs(x+1,map[num].arr[i]);   
    }  
}  
int main()  
{  
    int x,y,i,j,k;  
    cin>>n>>m;  
    for (i=1; i<=m; i++)  
    {  
        scanf("%d%d",&x,&y);  
        map[x].arr.push_back(y);  
        map[y].arr.push_back(x);  
    }  
    for (i=1; i<=n; i++)  
    {  
        b[1] = i;  
        dfs(2,i);//寻找 从i出发的路   
    }  
    cout<<cnt;  
    return 0;  
}   
