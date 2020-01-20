#include<iostream>
#include<cstring>
using namespace std;

int dp[1200][1200];//dp[i][j]表示a,b在前i,j个字符的min edit dis，so 0时dis=0
int mi(int a,int b,int c) {
	a=min(a,b);
	return min(a,c);
}
int main() {
	string a,b;
	while(cin>>a>>b) {
		int k1=a.length();
		int k2=b.length();
		a=' '+a;
		b=' '+b;
		memset(dp,0,sizeof(dp));
		for(int i=0; i<=k1; i++) dp[i][0]=i;
		for(int j=0; j<=k2; j++) dp[0][j]=j;

		for(int i=1; i<=k1; i++)
			for(int j=1; j<=k2; j++) {
				if(a[i]==b[j]) {
					dp[i][j]=dp[i-1][j-1];
				} else {
					dp[i][j]=mi(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1);//3情况分别表示：a删，a补，a换
				}
			}
		cout<<dp[k1][k2]<<endl;
	}

	return 0;
}
