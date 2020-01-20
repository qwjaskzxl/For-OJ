#include<iostream>
#include<algorithm>
using namespace std;
string a[1000];

int main()
{
	int i=0;
	while(cin>>a[i++])
	{
		if(getchar()=='\n') break;	
	}
	for(int j=i-1;j>0;j--)
		cout<<a[j]<<' ';
	cout<<a[0];
	return 0;
}
