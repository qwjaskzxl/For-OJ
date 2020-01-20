#include<iostream>
#include<string.h>
using namespace std;
int A[50005];
int main()
{
	memset(A,0,sizeof(A));
	int n,m;
	cin>>n>>m;	
	for(int i=1;i<=n;i++)
		cin>>A[i];
	
	while(m--)
	{
		int a=1,b=n;//上下界
		int ans=-1;//初始化为：找不到的情况 
		int x;cin>>x;
		while(a<=b)
		{
			int mid=(a+b)/2;
			if(x==A[mid])
			{
				ans=mid;
				break;
			}
			else if(x>A[mid])
			{
				a=mid+1;
			}
			else if(x<A[mid])
			{
				b=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

