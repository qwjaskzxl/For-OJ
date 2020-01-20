#include<iostream>
#include<string.h>
#include<typeinfo>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	char a[100];
	while(getline(cin,a))
	{
		sort(a.begin(),a.end());
		printf("%s\n",a.c_str());
	}
	return 0;
}
