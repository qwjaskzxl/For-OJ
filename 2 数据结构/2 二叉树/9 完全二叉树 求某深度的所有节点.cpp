#include<iostream>
#include<cmath>
using namespace std;
int a[1005];//2^10��1024��so����11��
int n,x;
int main() {
	while(cin>>n,n!=0) {
		for(int i=1; i<=n; i++)//�Լ���һ����ȫ��������һ���1��ʼ 
			cin>>a[i];
		cin>>x;
		if(pow(2,x-1)>n) printf("EMPTY");
		else for(int i=pow(2,x-1); i<pow(2,x); i++) {
			printf("%d ", a[i]);
			}
		printf("\n");
	}

	return 0;
}
