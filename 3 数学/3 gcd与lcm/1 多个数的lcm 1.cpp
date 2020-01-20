#include <iostream>
using namespace std;
int gcd(int a, int b) { //递归法
	return b==0? a:gcd(b,a%b);
}
int lcm(int a,int b) {
	return a/gcd(a,b)*b;//哇这里可能溢出了！ 
}
int main() {
	int T,n,a,b;
	cin>>T;
	while(T--) {
		cin>>n>>a;//考虑了n==1的情况，这样的话下面的循环不会执行，直接输出a。但是，n总不能==0吧 
		for(int i=0; i<n-1; i++) {
			cin>>b;
			a=lcm(a,b);
		}
		cout<<a<<endl;
	}
	return 0;
}
