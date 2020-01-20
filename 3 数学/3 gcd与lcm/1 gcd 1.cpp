#include <iostream>
using namespace std;
int gcd(int a, int b) { //递归法
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main() {
	int a,b,t;//原理是a与b，转化为b与a%b
	while(cin>>a>>b) {
		while(b!=0) { //循环法
			t=a%b;
			a=b;
			b=t;
		}
//		cout<<a<<endl;
		cout<<gcd(a,b)<<endl;//递归法
	}
	return 0;
}
