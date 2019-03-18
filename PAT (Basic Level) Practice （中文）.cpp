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
