#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int prime[10005];//保存筛到的素数
int pri_n=0;//素数个数
int mark[10005];//1：已标记 不用再判断其是否为素数
void search_prime() {//埃筛，O(nloglogn)
	memset(mark,0,sizeof(mark));
	for(int i=2; i<=10000; i++) {//最多只能46000这个数量级，因为46*46=2116快到了int最大范围
		if(mark[i]) continue;//已标记		
		prime[pri_n++]=i;//没标记到的，一定是素数 
		for(int k=i*i; k<=10000; k+=i)//素数的倍数都标记上已访问（他们是非素数
			mark[k]=1;		
	}
//	for(int i=0; i<pri_n; i++)
//		cout<<prime[i]<<' ';
}
int main() {
	search_prime();
	int n, i, ok;//2<=n<=10000
	while(cin>>n) {
		for(i=0,ok=0; n>prime[i]; i++) {
			if(prime[i]%10==1) {
				printf("%d ", prime[i]);
				ok=1;
			}
		}
		if (ok) printf("\n");
		else printf("-1\n");
	}
	return 0;
}
