//https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N=2005;
const int INF=0x7fffffff;
int a[N],vis[N];
set<int>se;
set<int>::iterator it;

int main() {
	int n;
	cin>>n;
	memset(vis,0,sizeof(vis));
	se.clear();
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		int t=a[i];
		while(t!=1) {
			if(t&1) { //ÆæÊý
				t=(3*t+1)>>1;
				vis[t]=1;
			} else {
				t>>=1;
				vis[t]=1;
			}
		}
	}
	for(int i=0; i<n; i++) {
		if(vis[a[i]]==0) {
			se.insert(a[i]);
		}
	}
	int j=0;
	for(it=se.end(); it!=se.begin(); ) {
		if(!j) {
			printf("%d", *--it);
			j=1;
		} else printf(" %d", *--it);
	}
	return 0;
}
