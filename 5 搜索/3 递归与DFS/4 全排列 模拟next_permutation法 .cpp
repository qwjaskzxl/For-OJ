#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s,ans;
int vis[26];
int n;

int DFS(int x, int is) {//λ��x��is�������Ƿ���������
	if(x==n) {
		cout<<ans<<endl;
	}
	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			if(is==0) {//������>=ԭ��λ�õ���ֵ���ſ��Է�
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
					DFS(x+1,is);//����Ҳ��Ҫ�жϱ�����>=���ܷ�
					vis[i]=0;
					ans.pop_back();
				}
			} 
			else if(is==1) { //��������
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
		n=strlen(s.c_str());//������s.length()�����s.size()һ������resize�ĳ���һ��
		ans="";
//		sort(s.begin(),s.begin()+n);
		DFS(0,0);
		printf("\n");//������puts("") ���Զ����ϻ���
	}
	return 0;
}
