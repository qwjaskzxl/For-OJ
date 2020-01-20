#include<iostream>
using namespace std;
int main() {//10:57->11:07
	int n;//»ð¼¦Êý 1~99
	int a,b,c;
	while(scanf("%d%d%d%d", &n,&a,&b,&c)!=EOF) {
		int k=a*1000+b*100+c*10;
		int ok=0;
		for(int i=9; i>=1&&!ok; i--) {
			for(int j=9; j>=0&&!ok; j--) {
				int s=i*10000+k+j;
				if(double(s)/n==s/n) {
					printf("%d %d %d\n", i,j,s/n);
					ok=1;
				}
			}
		}
		if(!ok) printf("0\n");
	}
	return 0;
}

