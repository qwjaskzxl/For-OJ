#include<iostream>
#include<cstring>
using namespace std;
const int N=30;
int a[N];
int dp[N];//��ÿ����ai���������������е�Ԫ����

int main() {
	int n;
	while(cin>>n, n!=0) {
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for(int i=0; i<n; i++) {
			int tmax=1;//��Ϊ������о��Ǳ������Ԫ�أ�so��1
			for(int j=0; j<i; j++) {//���ѭ����Ŀ�ľ����ҵ���ai��β��LIS��Ԫ����
				if(a[j]>=a[i]) {
					if(dp[j]+1>tmax)
						tmax=dp[j]+1;//����ǻ���ǰ���Ѿ��ҵ��˵�lIS�����ܷ���������ϸ�������
				}
			}
			dp[i]=tmax;
		}
		int ans=-1;
		for(int i=0; i<n; i++)
			if(dp[i]>ans)
				ans=dp[i];
		printf("%d\n", ans);
	}
	return 0;
}
