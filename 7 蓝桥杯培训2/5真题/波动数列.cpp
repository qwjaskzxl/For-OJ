//#include<bits/stdc++.h>
//#include<vector>
//using namespace std;
//const int Mod=100000007;
//
//int main()
//{
//	
//}
#include<bits/stdc++.h>
using namespace std;

int n,a[10],vst[10];
int DFS(int step)
{
	if(step==n+1)
	{
		for(int i=1;i<=n;i++) 
			cout<<a[i];
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])//没被放 
		{
			vst[i]=1;//如果不写可以试试，很有趣 
			a[step]=i;//放上i号球 
			DFS(step+1); 
			vst[i]=0;//把球拿出来 
		}
	}
	return 0;//作用其实是表示 函数结束，类似main里的return 0 
}

int main()
{
	memset(vst,0,sizeof(vst));
//	vst[3][3]=1;
	DFS(1);
	cout<<n/4; //因为中心对称 
}
