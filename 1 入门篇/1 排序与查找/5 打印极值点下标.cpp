//AC
#include<iostream>
#include<string.h>
using namespace std;
int a[80];
int b[80];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(b,0,sizeof(b));
		int n; cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		if(a[0]!=a[1]) b[0]=1;
		if(a[n-2]!=a[n-1]) b[n-1]=1;
		for(int j=1;j<n-1;j++)
		{
			if(a[j]<a[j-1] && a[j]<a[j+1] ||
			   a[j]>a[j-1] && a[j]>a[j+1])
			b[j]=1;			
		}
		for(int i=0;i<n;i++)
		{
			if(b[i]!=0) printf("%d ",i);
		}
		cout<<endl;
	}
	return 0;
}
