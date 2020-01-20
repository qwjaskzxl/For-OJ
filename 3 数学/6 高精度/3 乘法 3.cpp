#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],c[maxn*maxn];//c来存储结果
string s1,s2;

int main() {
	while(cin>>s1>>s2) {
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
		for(i=k1+k2; i>=2; i--)//记录第一个非0值的位置 ，一定是到2，因为最后一个无论如何都要输出，因为可能ans就是0 
			if(c[i]!=0) break;
		for(j=i; j>=1; j--)
			printf("%d", c[j]);
		printf("\n");
	}
	return 0;
}
