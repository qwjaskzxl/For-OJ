#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s,ans;
int vis[26];
int n;

void DFS(int x) {
	if(x==n) {
		cout<<ans<<endl;
		return ;//若不return,那数字放完后还要执行下面的for循环，而恰好vis都是0，可以永远递归下去，于是程序终止了？ 
	}
	else for(int i=0; i<n; i++) {//写else其实就可以不写return了 
		if(!vis[i]) {
			vis[i]=1;
			ans+=s[i];
			DFS(x+1);
			vis[i]=0;
			ans.pop_back();
		}
	}
}
int main() {
	s.resize(10);//scanf("%s", &s[0])
	while(scanf("%s", &s[0])) {
		memset(vis,0,sizeof(vis));
		n=strlen(s.c_str());//不能用s.length()这个和s.size()一样，是resize的长度一样
		ans="";
//		sort(s.begin(),s.begin()+n);//牛客的问题
		DFS(0);
		printf("\n");//或者用puts("") 会自动加上换行
	}
	return 0;
}
