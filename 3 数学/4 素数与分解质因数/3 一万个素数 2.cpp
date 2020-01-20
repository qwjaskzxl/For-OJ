#include<iostream>
#include<cstring>
#include<cmath>
typedef unsigned long long LL;
using namespace std;
LL prime[10005];//保存筛到的素数
int pri_n=0;//素数个数
int mark[100005];//1：已标记 不用再判断其是否为素数
void search_prime() {//埃筛，O(nloglogn)
	memset(mark,0,sizeof(mark));
	for(LL i=2; i<=104740; i++) {//最多只能46000这个数量级，因为46*46=2116快到了int最大范围
		if(mark[i]) continue;//已标记
		prime[pri_n++]=i;
		for(LL k=i*i; k<=100000; k+=i)//素数的倍数都标记上已访问（他们是非素数
			mark[k]=1;		 
	}
//	cout<<pri_n;
//	for(int i=0; i<pri_n; i++)
//		cout<<prime[i]<<' ';
}
int main() {
	search_prime();
	int n;//2<=n<=10000
	while(cin>>n) {
		printf("%d\n", prime[n-1]);
	}
	return 0;
}
