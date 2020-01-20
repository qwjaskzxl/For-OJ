#include<iostream>
using namespace std;
int main() { //ÎÒ17:31->17:35
	for(int i=1000;i<9999;i++)
	{
		int k=0,t=i;
		while(t>0){
			k=k*10+t%10;
			t/=10;
		}
		if(i*9==k) printf("%d\n", i);
	}
	return 0;
}

