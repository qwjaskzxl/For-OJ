//https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
#include<iostream>
#include<cstring>
using namespace std;
const int N=10005;
const int INF=0x7fffffff;
int a[N];
struct node {
	int m;
	int x,y;
} dp[N]; //遍历到前i个时的max
int n;
int main() {
	while(cin>>n) {
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		memset(dp, 0, sizeof(node));//这样全体赋值 
		dp[0].m=a[0];
		for(int i=1; i<n; i++) {
			if(dp[i-1].m+a[i]>a[i]) {
				dp[i].m=dp[i-1].m+a[i];
				dp[i].x=dp[i-1].x;
				dp[i].y=i;
			} else {
				dp[i].m=a[i];
				dp[i].x=dp[i].y=i;
			}
		}
		int ans=-INF,x,y;
		for(int i=0; i<n; i++) {
			if(dp[i].m>ans) {
				ans=dp[i].m;
				x=dp[i].x;
				y=dp[i].y;
			}
		}
		if(ans>=0)//注意等号 
			printf("%d %d %d\n", ans,a[x],a[y]);
		else
			printf("0 %d %d\n",a[0],a[n]);
	}
	return 0;
}
/*
10
-10 1 2 3 4 -5 -23 3 7 -21
*/
