#include<iostream>
using namespace std;
unsigned long long a[91]= {1,2};
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=2; i<n; i++)
			a[i]=a[i-1]+a[i-2];
		cout<<a[n-1]<<endl;
	}
	return 0;
}
