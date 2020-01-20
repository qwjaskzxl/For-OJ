#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int prime[35000];//32768
int pri_map[35000];//O(1)≈–∂œ «∑Ò «Àÿ ˝
int mark[35000];
void search_pri() {
	memset(pri_map,0,sizeof(pri_map));
	memset(mark,0,sizeof(mark));
	int pri_n=0;
	for(int i=2; i<32768; i++) {
		if(mark[i]) continue;
		prime[pri_n++]=i;
		pri_map[i]=1;
		for(int j=i*i; j<32768; j+=i)
			mark[j]=1;
	}
//	cout<<pri_n<<'\n';
//	for(int i=0; i<pri_n; i++) cout<<prime[i]<<' ';
//	for(int i=0;i<1000;i++) cout<<pri_map[i]<<" ";
}
int main() {//15:27-15:54
	search_pri();
	int n;
	while(cin>>n, n!=0) {
		int cnt=0;
		for(int i=0; prime[i]<=n/2; i++) {
			if(pri_map[n-prime[i]]) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
