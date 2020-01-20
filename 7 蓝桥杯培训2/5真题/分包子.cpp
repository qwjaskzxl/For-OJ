#include<bits/stdc++.h>
using namespace std;
int a,b,n,cnt=0,Flag;
//int a[101];
void DFS(int x,int y,int n)
{
	if(a*x+b*y>n) return ;
	if(a*x+b*y==n)
	{
		Flag=0;
		return ;
	}
	
	DFS(x+1,y,n);
	DFS(x,y+1,n);
	
}
int main()
{
//	cin>>n;
//	for(int i=1;i<=n;i++)
	{
//		cin>>a[i];
		cin>>a>>b; 
	}
	for(int i=1;i<=a*b-a-b;i++)//有数学证明的。。 
	{
		Flag=1;
		DFS(0,0,i);
		cout<<i<<' '<<Flag<<endl;
		cnt+=Flag;
	}
	cout<<cnt;
}
