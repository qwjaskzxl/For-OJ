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
		return ;//����return,�����ַ����Ҫִ�������forѭ������ǡ��vis����0��������Զ�ݹ���ȥ�����ǳ�����ֹ�ˣ� 
	}
	else for(int i=0; i<n; i++) {//дelse��ʵ�Ϳ��Բ�дreturn�� 
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
		n=strlen(s.c_str());//������s.length()�����s.size()һ������resize�ĳ���һ��
		ans="";
//		sort(s.begin(),s.begin()+n);//ţ�͵�����
		DFS(0);
		printf("\n");//������puts("") ���Զ����ϻ���
	}
	return 0;
}
