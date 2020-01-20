#include<iostream>
using namespace std;
/*
1.括空格的字符串的读取方法，这里很容易出bug
2.不区分大小写就可以先都转为为小写，利用tolower()函数，对单个字符操作
  或者用 (abs(a - b) == 32 || a == b)判断两个字符相等
3.可以直接把char数组赋值给string
4.string的erase操作是 要删除的起始位置+长删除的度
*/
char str[100000];
int main()
{
	string x;
	cin>>x;
	getchar();//吃掉第一行最后那个换行符
	for(int i=0; i<x.size(); i++) //因为不区分大小写，这里全部转化为小写
		x[i]=tolower(x[i]);
		
	while(gets(str))
	{
		string s=str,s_ori=str;//需要保留原串，以及用来匹配的小写串
		for(int i=0; i<s.size(); i++)
			s[i]=tolower(s[i]);
		while(s.find(x)!=string::npos)
		{
			int t=s.find(x);
			s.erase(t,x.size());
			s_ori.erase(t,x.size());
		}

		for(int i=0; i<s_ori.size(); i++)
			if(s_ori[i]!=' ')
				cout<<s_ori[i];
		cout<<endl;
	}
	return 0;
}
