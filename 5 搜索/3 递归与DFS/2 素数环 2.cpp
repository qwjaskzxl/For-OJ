#include<iostream>
#include<cstring>
using namespace std;
const int N=17;
int prime[]= {2,3,5,7,11,13,17,19,23,29,31}; //15+16=31，最多到31就够了
int n;
int ans[N];
int vis[N];

int check(int x) {
	for(int i=0; i<11; i++) { //到31是第12个素数
		if(x==prime[i]) return 1;
	}
	return 0;
}

void DFS(int num) {
	if(num>1 && check(ans[num-1]+ans[num])==0) //num>1时才可以前后比较呀！
		return ;
	if(num==n && check(ans[n]+ans[1])) {
		for(int i=1; i<=n; i++)
			printf("%d ",ans[i]);
			printf("\n");
		return ;
	}
	for(int i=2;i<=n;i++){
		if(!vis[i]) {
			vis[i]=1;
			ans[num+1]=i;
			DFS(num+1);
			vis[i]=0;//回溯		
		}		
	}
}

int main() {
	for(int i=1;; i++) {
		cin>>n;
		memset(vis,0,sizeof(vis));
		ans[1]=vis[1]=1;
		printf("Case %d:\n", i);
		DFS(1);
	}
	return 0;
}
