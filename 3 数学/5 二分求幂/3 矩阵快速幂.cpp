#include<iostream>
#include<cstring>
using namespace std;
const int M=9973;
const int maxn=11;
int a[maxn][maxn];
int b[maxn][maxn];
int T,n,k;
void mul(int a[][maxn], int b[][maxn]) { //这里传的是地址，可以改变数据实际的
	int t[maxn][maxn];
	memset(t,0,sizeof(t));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				t[i][j]=(t[i][j]+a[i][k]%M*(b[k][j]%M))%M;//i,j控制行列，k控制每一项的乘积求和
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			b[i][j]=t[i][j];
		}
}
void Pow(int a[][maxn], int b[][maxn]) {
	while(k>0) {
		if(k&1!=0) {
			mul(a,b);//传的是地址，可以改变实际的a,b数组的值！
		}
		mul(a,a);
		k>>=1;//除以2
	}
}
int main() {
	cin>>T;
	while(T--) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));//这个也要先初始化！
		scanf("%d%d", &n,&k);//k>=2
		for(int i=1; i<=n; i++)//涉及矩阵快速幂，一定是方阵
			for(int j=1; j<=n; j++)
				scanf("%d", &a[i][j]);
		for(int i=1; i<=n; i++) b[i][i]=1; //存ans，初始化为1。卧槽为什么放前面b会被men成0啊
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
