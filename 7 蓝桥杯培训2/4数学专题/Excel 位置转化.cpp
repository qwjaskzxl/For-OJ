/*题目描述：
Excel是最常用的办公软件。每个单元格都有唯一的地址表示。比如：第12行第4列表示为：“D12”，第5行第255列表示为“IU5”。 事实上，Excel提供了两种地址表示方法，还有一种表示法叫做RC格式地址。 第12行第4列表示为：“R12C4”，第5行第255列表示为“R5C255”。 你的任务是：编写程序，实现从RC地址格式到常规地址格式的转换。

输入：
用户先输入一个整数n（n<100），表示接下来有n行输入数据。

接着输入的n行数据是RC格式的Excel单元格地址表示法。
输出：
程序输出n行数据，每行是转换后的常规地址表示法。

样例输入
2
R12C4
R5C255
样例输出
D12
IU5
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
char Z[28]={"0ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
vector<char>v,CC;
int main()
{
	int n;cin>>n;
	int R,C;
	while(n--)
	{
		CC.clear();
		getchar();//很重要...吃掉？换行符？ 	
		scanf("R%dC%d",&R,&C);	//为什么没想到呢！			
		while(C%26)
		{		
			CC.push_back(Z[C%26]);
			C/=26;	
		}
//		reverse(CC.begin(),CC.end());//翻转
		for(int i=CC.size()-1;i>=0;i--)
			cout<<CC[i];
		cout<<R<<endl;
	}
}
