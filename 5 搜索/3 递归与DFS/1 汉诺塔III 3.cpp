#include<iostream>
using namespace std;
unsigned long long F(unsigned long long n) {
	if(n==1) return 2;
	else return 3*F(n-1)+2;
}
int main() {
	unsigned long long n;//1<=n<=35
	while(scanf("%lld", &n)!=EOF){
		printf("%lld\n", F(n));
	}
	return 0;
}
