#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s,ans;
int vis[26];
int n;

int DFS(int x, int is) {//位置x，is：后面是否可以随便排
	if(x==n) {
		cout<<ans<<endl;
	}
	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			if(is==0) {//必须是>=原来位置的数值，才可以放
				if(s[i]>s[x]) {
					vis[i]=1;
					ans+=s[i];
					is=1;
					DFS(x+1,is);
					is=0;
					vis[i]=0;
					ans.pop_back();
				} 
				else if(s[i]==s[x]) {
					vis[i]=1;
					ans+=s[i];
					DFS(x+1,is);//后面也是要判断必须是>=到能放
					vis[i]=0;
					ans.pop_back();
				}
			} 
			else if(is==1) { //可以随便放
				vis[i]=1;
				ans+=s[i];
				DFS(x+1,1);
				vis[i]=0;
				ans.pop_back();
			}
		}
	}
}
int main() {
	s.resize(10);//scanf("%s", &s[0])
	while(scanf("%s", &s[0])) {
		memset(vis,0,sizeof(vis));
		n=strlen(s.c_str());//不能用s.length()这个和s.size()一样，是resize的长度一样
		ans="";
//		sort(s.begin(),s.begin()+n);
		DFS(0,0);
		printf("\n");//或者用puts("") 会自动加上换行
	}
	return 0;
}
