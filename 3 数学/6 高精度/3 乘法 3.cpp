#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],c[maxn*maxn];//c���洢���
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
					c[i+j]+=c[i+j-1]/10;//��λ 
					c[i+j-1]%=10;//ȡ��λ
				}
			}
		}
		for(i=k1+k2; i>=2; i--)//��¼��һ����0ֵ��λ�� ��һ���ǵ�2����Ϊ���һ��������ζ�Ҫ�������Ϊ����ans����0 
			if(c[i]!=0) break;
		for(j=i; j>=1; j--)
			printf("%d", c[j]);
		printf("\n");
	}
	return 0;
}
