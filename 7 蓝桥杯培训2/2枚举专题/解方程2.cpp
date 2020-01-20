#include <bits/stdc++.h> 
using namespace std;
unsigned long long T,n;
unsigned long long F(int i,int t)
{	
	if(t==0) return i;
	else if(t==1) return i+2*F(i,t-1)-1;
	else return 3*F(i,t-1)-2*F(i,t-2)-1; 
}
int main()
{
	cin>>T>>n;
	for(int i=1; i<=3;i++)
	{
//		if(F(i,T)==n){
//			cout<<i;
//			break;
//		}
		cout<<F(i,T)<<endl;
	}
	
}
