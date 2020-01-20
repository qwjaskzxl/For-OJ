#include<bits/stdc++.h>
using namespace std;
int n=8,cnt=0;
int vst[3][100],C[10];
int Search(int cur)
{
	if(cur==n) cnt++;//没写return因为。。执行完也结束了 
	else for(int i=0;i<n;i++)
	{
		if(!vst[0][i] && !vst[1][cur+i] && !vst[2][cur-i+n])
		{
//			C[cur]=i;
			vst[0][i]=vst[1][cur+i]=vst[2][cur-i+n]=1;
			Search(cur+1);
			vst[0][i]=vst[1][cur+i]=vst[2][cur-i+n]=0;
		}
	}
}
int main()
{	
	memset(vst,0,sizeof(vst));
//	cin>>n;
	Search(0);	
	cout<<cnt;	
}

//#include <iostream>
//using namespace std;
//const int maxn=105;
//const int mo=100;
//typedef long long ll;
//int a[maxn],n = 8,ans=0;
//bool b[maxn],c[maxn],d[maxn];
//void sou(int x){
//    if(x > n){
//        ans++;
//        return;
//    }
//    for(int i = 1;i <= n;i++)
//	if(!(b[i] || c[x+i] || d[x-i+n])){
//        b[i] =c [x+i]=d[x-i+n]=1;
//        a[x] = i;
//        sou(x+1);
//        b[i] =c [x+i] = d[x-i+n]=0;
//    }
//}
//int main(){
//    sou(1);
//    cout<<ans;
//}

//#include<stdio.h>
//#include<iostream>
//using namespace std;
////dfs，每行只能放一个元素，遍历每行的每个位置，用一个一维数组记录，最后检查是否符合要求
//int ans;
//int vis[10];
//int abs(int x){
//    return x > 0 ? x : -x;
//}
//bool check(int r,int c){
//    for(int i = 1;i<r;i++){
//        if(vis[i] == c) return false;
//        if(vis[i] - c == r - i || vis[i] - c == i - r) return false;
//    }
//    return true;
//}
//void dfs(int r){
//    if(r > 8){
//        ans++;
//        return;
//    }
//    for(int i = 1;i<=8;i++){
//        if(check(r,i)){
//            vis[r] = i;
//            dfs(r+1);
//            vis[r] = 0;
//        }
//    }
//}
//main(){
//    dfs(1);
//    cout<<ans<<endl;
//}
