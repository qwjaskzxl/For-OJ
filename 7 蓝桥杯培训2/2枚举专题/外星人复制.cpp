#include<bits/stdc++.h>
using namespace std;

int main()
{
	double n,s;cin>>n>>s;
	double k,i,sum;//double还是厉害啊，long啥的都不行 
	for(i=1;sum!=s;i++)
	{
		sum=i;
		k=i;
		for(int j=0;j<n;j++)
		{
			k=2*k-1;
			sum+=k;
		}		
	}	
	cout<<i-1;
}
