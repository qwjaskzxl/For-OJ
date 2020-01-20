#include<iostream>
using namespace std;
const int N=105;
int a[N];
int dp1[N],dp2[N];//正向上升，反向上升！
int main() {//17:41->s
	int n,ma;
	while(scanf("%d",&n)!=EOF, n) {
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=0; i<n; i++) {
			ma=1;
			for(int j=0; j<i; j++) {
				if(a[j]<a[i])//上升
					ma=max(ma,dp1[j]+1);
			}
			dp1[i]=ma;
		}
		for(int i=n-1; i>=0; i--) {
			ma=1;
			for(int j=n-1; j>i; j--) {
				if(a[j]<a[i])//反向上升
					ma=max(ma,dp2[j]+1);
			}
			dp2[i]=ma;
		}
		
		ma=-1;
		for(int i=0; i<n; i++) {
			if(dp1[i]+dp2[i]>ma)
				ma=dp1[i]+dp2[i];
		}
		printf("%d\n", n-ma+1);
	}
	return 0;
}
