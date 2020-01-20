/*
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, a;
	while(scanf("%d", &n)!=EOF, n!=0) {
		while(n--) {
			scanf("%d", &a);
			if(a==1) printf("1\n");
			else {
				int i, cnt=2;//1和自己一定是
				for(i=2; i*i<a; i++) { //"等于"在后面单独判断
					if(a%i==0) cnt+=2;
				}
				if(i*i==a) cnt++;
				printf("%d\n", cnt);
			}
		}
	}
	return 0;
}
*/

//数学法，先分解质因数
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
//#define maxn 40000
const int maxn=35000;
int prime[maxn];
int mark[maxn];
int pri_n=0;

int main() {
	memset(mark, 0, sizeof(mark));
	for(int i=2; i<maxn; i++) {
		if(mark[i]) continue;
		prime[pri_n++]=i;
		if(i>sqrt(maxn)) continue;//不然下面可能也超int范围
		for(int j=i*i; j<maxn; j+=i)
			mark[j]=1;
	}
	int n, a;
	while(scanf("%d", &n)!=EOF, n!=0) {
		while(n--) {
			int cnt=0, ans=1;
			scanf("%d", &a);
			int k=sqrt(a), ok=0;
			for(int i=0; i<pri_n&&a>=prime[i]; i++) {//这个k>=prime[i]很传神啊
				while(a%prime[i]==0) {
					ok=1;
					cnt++;
					a/=prime[i];
				}
				if(ok) {
					ans*=cnt+1;
					cnt=ok=0;
				}
			}
			if(a!=1) ans*=2;//还有一个大的素数在后面，再乘(1+1)
			printf("%d\n", ans);
		}
	}
	return 0;
}
