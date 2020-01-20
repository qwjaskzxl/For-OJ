#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],vst[100]; 
long long cnt=0;
void DFS(int step)
{
	if(step==m+1)//这个全排列；可以改，也就是可以A43这样 
	{
//		for(int i=1;i<=m;i++)
//			cout<<a[i];
//		cout<<endl;
		cnt++;
		return ;
	}
	for(int i=1;i<=n;i++)//i是球 
	{
		if(!vst[i])//i号球没被放
		{
			a[step]=i;//放到step盒子 
			//if(a[step]<a[step-1]) continue;//生成组合数用，因为只有有序就OK了	
			vst[i]=1;//如果不写就是算几次幂，10的10要50s 
			DFS(step+1);//看下一个盒子
			vst[i]=0;//把球拿出来
		}
	}
	return ;//表示 函数结束，类似main里的return 0，不写应该也行 
}
int main()
{
	cin>>n>>m;
	DFS(1);//从1开始 
	cout<<cnt;
}
