#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;//之前手残用unsigned 结果一直underflow 。。 
LL a[605];
int cmp(LL x,LL y)
{
	return x>y;
}

int main()
{
	LL l,n;
	while(scanf("%lld%lld",&l,&n)!=EOF)
	{
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a,a+n,cmp);
		int sum=0;
		for(int i=0; i<n&&l>0; i++)
		{
			if(l>0)
			{
				l-=a[i];
				sum++;
			}
			else break;
		}
		if(l<=0) cout<<sum<<endl;
		else cout<<"impossible"<<endl;
	}
	return 0;
}
