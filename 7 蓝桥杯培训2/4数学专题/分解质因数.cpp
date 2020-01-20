#include <bits/stdc++.h> 
using namespace std;
vector<int>v,zs;
vector<int>::iterator it;
int N;
int main()
{	
	zs.push_back(2);
	for(int i=3;i<32768;i++)
	{
		int t=1;
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0) t=0;
		}
		if(t) zs.push_back(i);
	}
	
	cin>>N; cout<<N<<'=';
	for(int i=0;zs[i]<N;i++)
	{
		while(N%zs[i]==0) //直到不能被这个质数整除，再看下一个质数 
		{
			N/=zs[i];			
			cout<<zs[i];
			if(N==1) break; 
			cout<<'*';
		}
	}
	if(N!=1) cout<<N;	
}
