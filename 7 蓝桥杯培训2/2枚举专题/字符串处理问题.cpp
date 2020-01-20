#include<bits/stdc++.h> 
#include<set>
using namespace std;
set<char>SE;
unsigned long long F(unsigned long long n)
{
	while(n)
	{
		SE.insert(n%10);
		n/=10;
	}
}
unsigned long long Fs(unsigned long long n)
{
	while(n)
	{
		if(SE.count(n%10)) return 0;
		n/=10;
	}
	return 1;
}
int main()
{
	unsigned long long n,s;
	for(n=123456;n<=987654;n++)
	{
		SE.clear();
		F(n);
		if(SE.size()==6)
		{
			s=n*n;
			if(Fs(s)) 
			{
				cout<<s<<' '<<n<<endl;		
			}
		}				
	}
}
