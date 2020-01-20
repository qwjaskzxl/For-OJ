#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1001;
int a[maxn],b[maxn];
string s1,s2;
int main() {
	while(cin>>s1>>s2) { //假设都是正的，其实就算有负的，判断符号位之后，再看是否需要转为加法运算
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		string c="";//char类型不能定义为空，只好用了string
		if(s1.length()<s2.length() || s1.length()==s2.length()&&s1<s2) {
			c='-';
			string t=s1;
			s1=s2;
			s2=t;
		}
		int k1=s1.length();
		int k2=s2.length();
		int i;
		for(i=1; i<=k1; i++) a[i]=s1[k1-i]-'0';
		for(i=1; i<=k2; i++) b[i]=s2[k2-i]-'0';
		for(i=1; i<=k1; i++) {
			a[i]-=b[i];
			if(a[i]<0) {
				a[i+1]--;
				a[i]+=10;
			}
		}
		printf("%s", c.c_str());
		for(i=k1; i>=2; i--)
			if(a[i]!=0) break;//如果最后是0，则要输出0
		for(int j=i; j>=1; j--)
			printf("%d", a[j]);
		printf("\n");
	}
	return 0;
}
