#include<iostream>
using namespace std;
typedef unsigned long long LL;
const int M=200907; 
int main() {//21:27->21:
	int n,k;
	scanf("%d", &n);
	LL a,b,c;
	while(n--) {
		scanf("%lld%lld%lld%d", &a,&b,&c,&k);
		if(c-b==b-a) {//�Ȳ�
			LL d=b-a;
//			printf("%lld\n", (c%M+((k-3)%M*(d%M))%M)%M);//˵��abc���������������Ƿǵݼ��ģ�so dҲ>0 
			printf("%lld\n", (c+(k-3)*(d))%M);	
		} 
		else { //�ȱ�
			LL q=b/a, ans=1;//�������0�����ĳ�
			k--;//��Ϊ��a*q^(k-1)
			while(k>0) {
				if(k&1!=0)//������� 
					ans=(ans%M)*(q%M)%M;
				k>>=1;//����1bit����/2 
				q=(q%M)*(q%M)%M;
			}
			printf("%lld\n", (ans%M)*(a%M)%M);
		}
	}
	return 0;
}
