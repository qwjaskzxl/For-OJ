#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int N=1005;
stack<int>st;
int a[N];

int main(){
	int m,n,T;
	cin>>m>>n>>T;
	while(T--){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		while(!st.empty()) st.pop();
		int now=1;
		int ok=1;
		for(int i=1;i<=n;i++){
			st.push(i);
			if(st.size()>m) {
				ok=0;
				break;
			}
			while(!st.empty()&&st.top()==a[now]){//判空必须在前面写。。 
				st.pop();
				now++;
			}
		}
		if(ok && st.empty())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
