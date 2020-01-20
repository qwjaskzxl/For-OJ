#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
int a[N];
int dp[N];

int main() {//17:41->s
	int n;
	while(scanf("%d",&n)!=EOF, n!=0) {
		int p,ma=-1;
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			if(a[i]>ma) {
				ma=a[i];
				p=i;
			}
		}
//		memset(dp,0,sizeof(dp));
		for(int i=0; i<p; i++) {
			ma=1;
			for(int j=0; j<i; j++) {
				if(a[j]<a[i])
					ma=max(ma,dp[j]+1);
			}
			dp[i]=ma;
		}
		for(int i=p; i<n; i++) {//只要一遍带上p就行 
			ma=1;
			for(int j=0; j<i; j++) {
				if(a[j]>a[i])
					ma=max(ma,dp[j]+1);
			}
			dp[i]=ma;
		}

		ma=-1;
		for(int i=0; i<p; i++)
			if(dp[i]>ma)
				ma=dp[i];
		int cnt=ma;
		ma=-1;
		for(int i=p; i<n; i++)
			if(dp[i]>ma)
				ma=dp[i];
		cnt+=ma;
		printf("%d\n", n-cnt);
	}

	return 0;
}
