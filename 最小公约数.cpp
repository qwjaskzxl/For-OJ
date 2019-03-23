#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)//最大公约数；利用的公式gcd(a,b)=gcd(b,a%b) 
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<' '<<a*b/gcd(a,b);//a*b/最大公约数
	return 0;
}
