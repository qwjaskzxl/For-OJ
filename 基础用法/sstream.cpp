https://blog.csdn.net/joeblackzqq/article/details/7032703

#include<bits/stdc++.h>
#include<sstream>
using namespace std;
void i2s(int x,string &s)//可以直接把int 转string 
{
	stringstream ss;
// 	ss.clear();
// 	ss.str(s);
	ss<<x;
	ss>>s;
}
int main()
{
	int a=999;
	string b;
	i2s(a,b);
	cout<<a<<' '<<b;
	return 0;
}
//output:999 999


//另一个例子：
#include <iostream>
#include <sstream>
using namespace std; 
int main()
{
	istringstream istr;
	istr.str("1 56.7");
	//上述两个过程可以简单写成 istringstream istr("1 56.7");
	cout << istr.str() << endl;
	int a;
	float b;
	istr >> a;
	cout << a << endl;
	istr >> b;
	cout << b << endl;
	return 0;
}
//output:
// 1 56.7
// 1
// 56.7
上例中，构造字符串流的时候，空格会成为字符串参数的内部分界。
例子中对a,b对象的输入"赋值"操作证明了这一点，字符串的空格成为了整型数据与浮点型数据的分解点，
利用分界获取的方法我们事实上完成了字符串到整型对象与浮点型对象的拆分转换过程。
