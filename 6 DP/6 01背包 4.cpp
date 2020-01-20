#include<iostream>
using namespace std;
const int N=1005;
int w[N];//重量
int v[N];//收益
int dp[N][N];//dpij表示体积<=j时，前i个物品达到的最大收益
int W,n;//容量，物品数
void show_dp() {
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=W; j++)
			cout<<dp[i][j]<<' ';
		cout<<"\n";
	}
	cout<<"\n";
}
int main() {

	while(cin>>W>>n) {
		if(!W && !n) break;
		for(int i=1; i<=n; i++)//必须从1开始，因为0有“没选物品”的含义，不能缺少！
			cin>>w[i]>>v[i];
		for(int j=0; j<=W; j++) dp[0][j]=0;//没选的话，都是0 
		for(int i=1; i<=n; i++) {
			for(int j=w[i]; j<=W; j++)//够装 
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
			for(int j=w[i]-1; j>=0; j--)//不够装 
				dp[i][j]=dp[i-1][j];
//			show_dp();
		}
		cout<<dp[n][W]<<endl;
	}
	return 0;
}

/*
5 3
3 2
2 4
3 3
*/

#include<iostream>
using namespace std;
const int N=1005;
int w[N];//重量
int v[N];//收益
int dp[N];//体积<=j时，能达到的最大收益
int W,n;//容量，物品数
void show_dp() {
	for(int j=0; j<=W; j++)
		cout<<dp[j]<<' ';
	cout<<"\n\n";
}
int main() {
	
	while(cin>>W>>n) {
		if(!W && !n) break;
		for(int i=1; i<=n; i++)//必须从1开始，因为0有“没选物品”的含义，不能缺少！
			cin>>w[i]>>v[i];
		for(int j=0; j<=W; j++) dp[j]=0; //也要都init=0。理解为，虽把时间维度去了，
		//但是其实刚开始是要全部赋为0，表示了时间维度的意义，即“没选”时，收益都是0
		for(int i=1; i<=n; i++) {
			for(int j=W; j>=w[i]; j--)
				dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
//			show_dp();
		}
		cout<<dp[W]<<endl;
	}
	return 0;
}
