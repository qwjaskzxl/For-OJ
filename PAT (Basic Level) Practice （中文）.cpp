// B1002
// 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
// 输入样例：
// 1234567890987654321123456789
// 输出样例：
// yi san wu
#include<bits/stdc++.h> 
#include<string> 
#include<vector>
using namespace std;
//map<int,string>mapp;
vector<string>v;
vector<string>::iterator it;
string mapp[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
	string a;cin>>a;
	long long s=0;
	for(int i=0;i<a.length();i++)
	{
		s+=a[i]-'0';
	}	
	int t=0;
	while(s>0)
	{
		t=s%10;
		v.push_back(mapp[t]);
		s/=10;
	}
	for(it=v.end()-1;it>v.begin();it--)//或者i=v.size()-1;
	cout<<*it<<' ';
	cout<<*v.begin();	
	return 0;
}

// B1016
// 输入样例 1：
// 3862767 6 13530293 3
// 输出样例 1：
// 399
#include <iostream>
#include <sstream>
using namespace std; 
int main()
{
	long long a, b;
	string s1, s2;
	cin>>s1>>a>>s2>>b;
	int p1=0, p2=0;
	stringstream ss;
	ss>>a>>b;
	ss<<s1<<s2;
	for(int i=0; i<s1.length();i++)
//		if(s1.find(a+'0')!=string::npos) //这个用来检测有没有，我这是要检测个数		
		if(s1[i]-'0'==a) p1=p1*10+a;
		
	for(int i=0; i<s2.length();i++)
		if(s2[i]-'0'==b) p2=p2*10+b;
	cout<<p1+p2;		
  return 0;
}
