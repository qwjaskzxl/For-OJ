#include <iostream>
#include<cmath>
using namespace std;
typedef unsigned long long LL;
int main() {//16:53->17:22 用了29min
	int a,b;//a->b进制
	string n;
	while(cin>>a>>n>>b) {
		LL sum=0;
		for(int i=0; i<n.length(); i++) {
			if(n[i]>='0'&&n[i]<='9')
				sum+=(n[i]-'0')*pow(a,n.length()-i-1);
			else if(n[i]>='a'&&n[i]<='z') {
				sum+=(10+n[i]-'a')*pow(a,n.length()-i-1);
			} 
			else if(n[i]>='A'&&n[i]<='Z') {
				sum+=(10+n[i]-'A')*pow(a,n.length()-i-1);
			}
		}
//		cout<<sum<<endl;
		string ans;
		do {
			if(sum%b>=10)
				ans+='A'+sum%b%10;//加上尾数即可
			else ans+=sum%b+'0';
			sum/=b;
		} while(sum>0);
		for(int i=ans.length()-1; i>=0; i--)
			cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
