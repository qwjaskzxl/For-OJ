/*
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, a;
	while(scanf("%d", &n)!=EOF, n!=0) {
		while(n--) {
			scanf("%d", &a);
			if(a==1) printf("1\n");
			else {
				int i, cnt=2;//1���Լ�һ����
				for(i=2; i*i<a; i++) { //"����"�ں��浥���ж�
					if(a%i==0) cnt+=2;
				}
				if(i*i==a) cnt++;
				printf("%d\n", cnt);
			}
		}
	}
	return 0;
}
*/

//��ѧ�����ȷֽ�������
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
//#define maxn 40000
const int maxn=35000;
int prime[maxn];
int mark[maxn];
int pri_n=0;

int main() {
	memset(mark, 0, sizeof(mark));
	for(int i=2; i<maxn; i++) {
		if(mark[i]) continue;
		prime[pri_n++]=i;
		if(i>sqrt(maxn)) continue;//��Ȼ�������Ҳ��int��Χ
		for(int j=i*i; j<maxn; j+=i)
			mark[j]=1;
	}
	int n, a;
	while(scanf("%d", &n)!=EOF, n!=0) {
		while(n--) {
			int cnt=0, ans=1;
			scanf("%d", &a);
			int k=sqrt(a), ok=0;
			for(int i=0; i<pri_n&&a>=prime[i]; i++) {//���k>=prime[i]�ܴ���
				while(a%prime[i]==0) {
					ok=1;
					cnt++;
					a/=prime[i];
				}
				if(ok) {
					ans*=cnt+1;
					cnt=ok=0;
				}
			}
			if(a!=1) ans*=2;//����һ����������ں��棬�ٳ�(1+1)
			printf("%d\n", ans);
		}
	}
	return 0;
}
