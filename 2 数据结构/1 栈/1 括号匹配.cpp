#include<iostream>
#include<stack>
using namespace std;
stack<int>s;//存左括号所在位置
int main()
{
	string a,b;
	while(cin>>a)
	{
		b=a;//单纯为了生成一个与输入等长的串
		for(int i=0; i<a.length(); i++)
		{
			b[i]=' ';//初始化
			if(a[i]=='(')
				s.push(i);
			if(a[i]==')')
			{
				if(s.empty())//若为空则说明匹配失败，想想栈的机理，和括号匹配是一样 
					b[i]='?';
				else s.pop();//不为空则把左括号出栈 
			}
		}
		while(!s.empty())
		{
			b[s.top()]='$';
			s.pop();//pop是没有返回值，所以用top取值 
		}
		cout<<a<<endl<<b<<endl;
	}
	return 0;
}
