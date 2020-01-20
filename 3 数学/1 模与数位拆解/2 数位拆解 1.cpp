#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[15],b[15];
int F(int x,int *m) {
	int i=0;
	while(x>0) {
		m[i++]=x%10;
		x/=10;
	}
	return i;
}
//int main() { //我17:08->17:16
//	int x,y;//int 能存2e10，够用了
//	while(cin>>x>>y) {
//		int na=F(x,a);
//		int nb=F(y,b);
//		int sum=0;
//		for(int i=0; i<na; i++)
//			for(int j=0; j<nb; j++) {
//				sum+=a[i]*b[j];
//			}
//		printf("%d\n", sum);
//	}
//	return 0;
//}

//法2
int main() { //我17:08->17:16
	string x,y;//int 能存2e10，够用了
	while(cin>>x>>y) {
		int sum=0;
		for(int i=0; i<x.length(); i++)
			for(int j=0; j<y.length(); j++) {
				sum+=(x[i]-'0')*(y[j]-'0');
			}
		printf("%d\n", sum);
	}
	return 0;
}

 
