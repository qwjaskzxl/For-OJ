#include <iostream>
using namespace std;
int gcd(int a, int b) { //�ݹ鷨
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main() {
	int a,b,t;//ԭ����a��b��ת��Ϊb��a%b
	while(cin>>a>>b) {
		while(b!=0) { //ѭ����
			t=a%b;
			a=b;
			b=t;
		}
//		cout<<a<<endl;
		cout<<gcd(a,b)<<endl;//�ݹ鷨
	}
	return 0;
}
