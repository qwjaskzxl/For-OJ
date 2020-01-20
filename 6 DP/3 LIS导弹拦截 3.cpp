#include<iostream>
#include<cstring>
using namespace std;
const int N=30;
int a[N];
int dp[N];//存每个以ai结果的最长递增子序列的元素数

int main() {
	int n;
	while(cin>>n, n!=0) {
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for(int i=0; i<n; i++) {
			int tmax=1;//因为最短序列就是本身这个元素，so，1
			for(int j=0; j<i; j++) {//这层循环的目的就是找到以ai结尾的LIS的元素数
				if(a[j]>=a[i]) {
					if(dp[j]+1>tmax)
						tmax=dp[j]+1;//这就是基于前面已经找到了的lIS，看能否在这基础上更“长”
				}
			}
			dp[i]=tmax;
		}
		int ans=-1;
		for(int i=0; i<n; i++)
			if(dp[i]>ans)
				ans=dp[i];
		printf("%d\n", ans);
	}
	return 0;
}
