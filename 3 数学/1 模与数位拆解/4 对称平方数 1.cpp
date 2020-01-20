#include<iostream>
using namespace std;
int main() { //ÎÒ17:37->17:49
	for(int i=0;i<=256;i++) //»¹ÓÐ0Ñ½£¡ 
	{
		int k=i*i,t=k,s=0;
		while(t>0){
			s=s*10+t%10;
			t/=10;
		}
		if(s==k) printf("%d\n", i);
	}
	return 0;
}
