#include<bits/stdc++.h>
#include<vector>
using namespace std;
unsigned long long n,m,p,a[1000000]={0,1,1};
int main()
{
	cin>>n>>m>>p;
	unsigned long long i,t,sum=0;
	
	for(i=1;i<=max(m,n)-2;i++)
	{
		a[i+2]=a[i+1]+a[i];	
	}
	for(i=1;i<=n;i++)
	{		
		sum+=a[i];
	}
	cout<<sum%a[m]%p;
}
//要用大数
