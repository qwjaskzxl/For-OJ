#include<iostream>
using namespace std;
int main() {//21:02->21:18
	int a,b;
	while(scanf("%d%d", &a,&b)!=EOF) {
		if(!a&&!b) break;
		int ans=1;
		while(b>0) {
			if(b&1!=0)//������� 
				ans=ans*a%1000;
			b>>=1;//����1bit����/2 
			a=a*a%1000;
		}
		printf("%d\n", ans);
	}
	return 0;
}
