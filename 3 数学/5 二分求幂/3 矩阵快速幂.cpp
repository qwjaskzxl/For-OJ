#include<iostream>
#include<cstring>
using namespace std;
const int M=9973;
const int maxn=11;
int a[maxn][maxn];
int b[maxn][maxn];
int T,n,k;
void mul(int a[][maxn], int b[][maxn]) { //���ﴫ���ǵ�ַ�����Ըı�����ʵ�ʵ�
	int t[maxn][maxn];
	memset(t,0,sizeof(t));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				t[i][j]=(t[i][j]+a[i][k]%M*(b[k][j]%M))%M;//i,j�������У�k����ÿһ��ĳ˻����
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			b[i][j]=t[i][j];
		}
}
void Pow(int a[][maxn], int b[][maxn]) {
	while(k>0) {
		if(k&1!=0) {
			mul(a,b);//�����ǵ�ַ�����Ըı�ʵ�ʵ�a,b�����ֵ��
		}
		mul(a,a);
		k>>=1;//����2
	}
}
int main() {
	cin>>T;
	while(T--) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));//���ҲҪ�ȳ�ʼ����
		scanf("%d%d", &n,&k);//k>=2
		for(int i=1; i<=n; i++)//�漰��������ݣ�һ���Ƿ���
			for(int j=1; j<=n; j++)
				scanf("%d", &a[i][j]);
		for(int i=1; i<=n; i++) b[i][i]=1; //��ans����ʼ��Ϊ1���Բ�Ϊʲô��ǰ��b�ᱻmen��0��
		Pow(a,b);
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++)
//				printf("%d ", b[i][j]);
//			cout<<endl;
//		}
		int sum=0;
		for(int i=1; i<=n; i++)
			sum+=b[i][i]%M;
		printf("%d\n", sum%M);
	}
	return 0;
}
/*
5
3 2
1 1 1
1 1 1
1 1 1
*/
