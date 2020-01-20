#include<iostream>
using namespace std;
const int N=105;
string a,b;
int dp[N][N];//dp[i][j]表示a和b在前i和j个字符时的LCS长度
int main() {
	while(cin>>a>>b) {
		int la=a.length();
		int lb=b.length();
		for(int i=0; i<=la; i++) dp[i][0]=0; //共la+1个数要init
		for(int j=0; j<=lb; j++) dp[0][j]=0;

		for(int i=1; i<=la; i++) {//1~la
			for(int j=1; j<=lb; j++) {
				if(a[i-1]==b[j-1])//把i-1当做上次位置，每次递推当前的i位置
					dp[i][j]= dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
			}
		}
		printf("%d\n", dp[la][lb]);
	}
	return 0;
}
