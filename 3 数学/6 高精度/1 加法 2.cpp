#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1001;
int a[maxn],b[maxn];
string s1,s2;
int main() {
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(cin>>s1>>s2) {
		if(s1.length()<s2.length() || (s1.length()==s2.length()&&s1<s2)) {
			string t=s1;
			s1=s2;
			s2=t;
		}
		int k1=s1.length();
		int k2=s2.length();
		for(int i=1; i<=k1; i++)//倒序存储
			a[i]=s1[k1-i]-'0';
		for(int i=1; i<=k2; i++)
			b[i]=s2[k2-i]-'0';

		for(int i=1; i<=k1; i++) {//从低位开始加
			a[i]+=b[i];
			if(a[i]>=10) {
				a[i+1]++;//进位
				a[i]-=10;
			}
		}
		if(a[k1+1]!=0) k1++;//检查最后是否有进位 
		for(int i=k1; i>=1; i--)
			printf("%d", a[i]);
		printf("\n");
	}
	return 0;
}
