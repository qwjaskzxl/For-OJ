#include<iostream>
using namespace std;
typedef unsigned long long LL;
const int M=200907; 
int main() {//21:27->21:
	int n,k;
	scanf("%d", &n);
	LL a,b,c;
	while(n--) {
		scanf("%lld%lld%lld%d", &a,&b,&c,&k);
		if(c-b==b-a) {//等差
			LL d=b-a;
//			printf("%lld\n", (c%M+((k-3)%M*(d%M))%M)%M);//说了abc都是正数，而且是非递减的，so d也>0 
			printf("%lld\n", (c+(k-3)*(d))%M);	
		} 
		else { //等比
			LL q=b/a, ans=1;//不会除以0，放心除
			k--;//因为是a*q^(k-1)
			while(k>0) {
				if(k&1!=0)//运算更快 
					ans=(ans%M)*(q%M)%M;
				k>>=1;//右移1bit就是/2 
				q=(q%M)*(q%M)%M;
			}
			printf("%lld\n", (ans%M)*(a%M)%M);
		}
	}
	return 0;
}
