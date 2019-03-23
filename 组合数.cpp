#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c(LL n,LL m)//O(m)
{
	LL ans=1;
	for(LL i=1;i<=n;i++)
	{
		ans=ans*(n-m+i)/i;
	}
}

int main()
{
	cout<<c(5,3);
	return 0;
}
