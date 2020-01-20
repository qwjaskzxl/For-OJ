#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 32623//int(sqrt(1e9))+1
int prime[maxn];
int mark[maxn];//从1开始 
int pri_n=0;
//虽然数据范围是10^9，但是顶多就一个 > sqrt(10^9)的素数 是他是质因数，所以留到最后判断即可
void search_pri() {
	memset(mark,0,sizeof(mark));
	for(int i=2; i<maxn; i++) {
		if(mark[i]) continue;
		prime[pri_n++]=i;
		if(i>int(sqrt(maxn))) continue;//简化运算		
		for(int j=i*i; j<maxn; j+=i)
			mark[j]=1;
	}
}
int main() {//15:27-15:54
	search_pri();
	int n;
	while(scanf("%d", &n) != EOF) {
		int cnt=0;
		for(int i=0; n>=prime[i]&&i<pri_n; i++) {
			while(n%prime[i]==0) { //以while代替if
				n/=prime[i];
				cnt++;
			}
		}
		if(n!=1) cnt++;//说明还有一个>32623的素数 
		cout<<cnt<<'\n';
	}
	return 0;
}
