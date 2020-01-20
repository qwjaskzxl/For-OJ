#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
const int N=105;
const int M=1000000007;
const int INF=0x7fffffff;
struct node {
	double a,b,c;
};
int n;
string a,b;
string deal(string &s, int &k){//因为两个string操作一样而且挺复杂的，用函数 
	while(s[i]=='0' && s.length()>0) 
		s.erase(s.begin());//去除前导零 
	string ret;
	if(s[0]=='.'){
		ret+='-';
		
	}
}
int main() {//coding 20:58->
	cin>>n>>a>>b;
	int e1=0,e2=0;//指数 
	deal(a,e1);
	deal(b,e2);
	
	for(int i=0; i<n&&i<la; i++) {
		if(a[i]=='.') {
			la2=i-1;
			continue;
		}
		a2+=a[i];
	}
	for(int i=0; i<n&&i<lb; i++) {
		if(b[i]=='.') {
			lb2=i-1;
			continue;
		}
		b2+=b[i];
	}
	while(a2.length()<n) a2+='0';
	while(b2.length()<n) b2+='0';
	if(a2==b2)
		cout<<"YES 0."<<a2<<"*10^"<<la2;
	else
		cout<<"NO 0."<<a2<<"*10^"<<la2<<" 0."<<b2<<"*10^"<<lb2;
	return 0;
}
/*
6 0.00123 0.01
*/
