#include <iostream>
using namespace std;
typedef unsigned long long LL;
int main() {
	LL a,b,k;//a,b是10进制
	while(cin>>k, k!=0) {
		cin>>a>>b;
		LL sum=a+b;
		string s;
		do {	//注意考虑0的问题！ 
			s+=sum%k+'0';
			sum/=k;
		}while(sum>0);
		for(int i=s.length()-1; i>=0; i--)
			cout<<s[i];
		cout<<endl;		
	}
	return 0;
}
