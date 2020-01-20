#include<iostream>
#include<cstring>
using namespace std;
const int M=9973;
const int maxn=11;
int T,n,k;
struct Mat {
	int mat[maxn][maxn];
} a,b;
Mat mul(Mat a, Mat b) {
	Mat t;
	memset(t.mat,0,sizeof(t.mat));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				t.mat[i][j]=(t.mat[i][j]+a.mat[i][k]%M*(b.mat[k][j]%M))%M;//i,j�������У�k����ÿһ��ĳ˻����
	return t;
}
Mat Pow(Mat a, Mat b) {
	while(k>0) {
		if(k&1)
			b=mul(a,b);
		a=mul(a,a);
		k>>=1;
	}
	return b;
}
int main() {
	cin>>T;
	while(T--) {
		memset(a.mat,0,sizeof(a.mat));
		memset(b.mat,0,sizeof(b.mat));//���ҲҪ�ȳ�ʼ���� 
		scanf("%d%d", &n,&k);//k>=2
		for(int i=1; i<=n; i++)//�漰��������ݣ�һ���Ƿ���
			for(int j=1; j<=n; j++) 
				scanf("%d", &a.mat[i][j]);			
		for(int i=1; i<=n; i++) b.mat[i][i]=1; //��ans����ʼ��Ϊ1���Բ�Ϊʲô��ǰ��b�ᱻmen��0��
		b=Pow(a,b);
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++)
//				printf("%d ", b.mat[i][j]);
//			cout<<endl;
//		}
		int sum=0;
		for(int i=1; i<=n; i++)
			sum+=b.mat[i][i]%M;
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
