#include<iostream>
#include<cmath>
using namespace std;
int a[1005];//2^10才1024，so最深11层
int n,x;
int main() {
	while(cin>>n,n!=0) {
		for(int i=1; i<=n; i++)//自己画一个完全二叉树，一般从1开始 
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
