#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1; i<=n; i++) //nÐÐ
		{
			for(int j=0; j<(n-i)*2; j++)
				cout<<' ';
			for(int j=0; j<n+(i-1)*2; j++)
				cout<<'*';
			cout<<endl;
		}
	}
	return 0;
}
