/*
有12张连在一起的12生肖的邮票。 
现在你要从中剪下5张来，要求必须是连着的。 
（仅仅连接一个角不算相连）
*/
#include<bits/stdc++.h>
#include<set>
using namespace std;
int n=12,m=5,cnt=0,T;
int a[13],vst[13],Vst[13]; 
int Map[13];
set<int>SE;
set<int>::iterator it;
void DFS(int x,int t)
{
	SE.insert(x);
	if(SE.size()==5) 
	{
//		for(it=SE.begin();it!=SE.end();it++)
//			cout<<*it;
//		cout<<'A'<<endl;
		cnt++;
		T=1;//防止多次检索 
		return ;
	}
	
	vst[x]=1;
	int Next[4]={1,-1,4,-4};
	for(int i=0;i<4;i++)
	{				
		if(T) break;
		if(x==4&&i==0||x==8&&i==0||x==5&&i==1||x==9&&i==1) continue;
		int tx=x+Next[i];
		if(!vst[tx]&&tx>0&&tx<=12&&Map[tx]==1) 
		{	
			vst[tx]=1;	
			DFS(tx,t+1);
			vst[tx]=0;
		} 
	} 
}
void C(int step)//生成所有组合
{	
	if(step==m+1)
	{
		memset(Map,0,sizeof(Map));
		memset(vst,0,sizeof(vst));
		
		for(int i=1;i<=m;i++)
		{
			Map[a[i]]=1;//5个选中色块 		
		}
		T=0; 
		SE.clear();
		DFS(a[1],0);//从最小的块开始DFS 		
		return ;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			a[step]=i;
			if(a[step]<a[step-1]) continue;	
			vst[i]=1;
			C(step+1);
			vst[i]=0;
		}
	}
}
int main()
{
	C(1);
	cout<<cnt;
}
