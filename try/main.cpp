#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1005;
const int INF=0x7fffffff;

int main() {
	int n,t,x,y,j=0;
	string a,b;
	cin>>n;
	while(1) {
		a=b="";
		t=n;
		for(int i=0; i<4; i++) {
			a+=t%10+'0';//0也会加到前面
			t/=10;
		}
		t=n;
		sort(a.begin(),a.end());//reverse(a.begin(),a.end())原地反转
		for(int i=3; i>=0; i--)
			b+=a[i];
		x=stoi(a);
		y=stoi(b);
		n=y-x;
		if(t==n) {
			if(!j) printf("%04d - %04d = %04d",y,x,n);
			break;
		}
		else {
			if(!j) {
				printf("%04d - %04d = %04d",y,x,n);
				j=1;
			} else printf("\n%04d - %04d = %04d",y,x,n);
		}
	}
	return 0;
}
