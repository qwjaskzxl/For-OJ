#include<bits/stdc++.h>
#include<sstream>
using namespace std;

void i2s(int x,string &s)
{
	stringstream ss;
	ss<<x;
	ss>>s;
}
int main()
{
	int a=999;
	string b;
	i2s(a,b);
	cout<<a<<' '<<b;
	return 0;
}

#output:999 999
