#include <iostream>
#include<cmath>
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		int k=(int)sqrt(n)+1,ok=1;
		if(n<=1) ok=0;
		for(int i=2; i<k; i++)
			if(n%i==0) {
				ok=0;
				break;
			}
		if(ok) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
