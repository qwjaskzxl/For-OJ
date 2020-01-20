#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],c[maxn*maxn];//c来存储结果

string cal(string s1, string s2) {
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c)); 
	int k1=s1.length();
	int k2=s2.length();
	int i,j;
	for(i=1; i<=k1; i++) a[i]=s1[k1-i]-'0';
	for(i=1; i<=k2; i++) b[i]=s2[k2-i]-'0';

	for(i=1; i<=k1; i++) {
		for(j=1; j<=k2; j++) {
			c[i+j-1]+=a[i]*b[j];
			if(c[i+j-1]>=10) {
				c[i+j]+=c[i+j-1]/10;//进位
				c[i+j-1]%=10;//取个位
			}
		}
	}
	for(i=k1+k2; i>=1; i--)//记录第一个非0值的位置
		if(c[i]!=0) break;
	s1="";
	for(j=i; j>=1; j--)
		s1+=c[j]+'0';
	return s1;
}

int main() {
	int n;
	while(cin>>n) {
		string s1="1",s2;
		if(n==0||n==1) printf("1\n");
		else {
			for(int i=2; i<=n; i++) {
				s2=to_string(i);
				s1=cal(s1, s2);
//				cout<<s1<<'\n';
			}
			printf("%s\n", s1.c_str());
		}
	}
	return 0;
}
