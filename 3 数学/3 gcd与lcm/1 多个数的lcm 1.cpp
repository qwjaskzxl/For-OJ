#include <iostream>
using namespace std;
int gcd(int a, int b) { //�ݹ鷨
	return b==0? a:gcd(b,a%b);
}
int lcm(int a,int b) {
	return a/gcd(a,b)*b;//�������������ˣ� 
}
int main() {
	int T,n,a,b;
	cin>>T;
	while(T--) {
		cin>>n>>a;//������n==1������������Ļ������ѭ������ִ�У�ֱ�����a�����ǣ�n�ܲ���==0�� 
		for(int i=0; i<n-1; i++) {
			cin>>b;
			a=lcm(a,b);
		}
		cout<<a<<endl;
	}
	return 0;
}
