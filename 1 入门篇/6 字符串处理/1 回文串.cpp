#include<iostream>
#include<algorithm>
using namespace std;
string a;

int main()
{
	cin>>a;
	string b=a;
	reverse(a.begin(),a.end());
	if(a==b)
	cout<<"YES";
	else cout<<"NO";
	return 0;
}
