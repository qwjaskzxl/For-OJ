/*
当屏幕出现22时，你的回答应是23；当屏幕出现8时，你的回答应是7；若X本身是素数，则回答X;若最接近X的素数有两个时，则回答大于它的素数。

输入：
第一行：N 要竞猜的整数个数 接下来有N行，每行有一个正整数X 1<=N<=5 1<=X<=1000

输出：
输出有N行，每行是对应X的最接近它的素数

样例输入
4
22
5
18
8
样例输出
23
5
19
7

#include<bits/stdc++.h> 
using namespace std;
vector<int>v;
vector<int>::iterator it;
int main()
{
	v.push_back(2);
	for(int i=3;i<=1000;i+=2) //除2之外的偶数都不是质数 
	{
		int t=1; 
		for(int j=2;j<=sqrt(i);j++)
		{			
			if(i%j==0) 
			{
				t=0;
				break;
			}									
		}
		if(t) v.push_back(i);
	}
	
	int n;cin>>n;
	while(n--)
	{
		int a;cin>>a;
		int mi=999;
		for(it=v.begin();it!=v.end();it++)
		{
			if(abs(*it-a)<mi) mi=abs(*it-a);
			else if(abs(*it-a)==mi){
				cout<<*it<<endl;
				break;
			}
			else{
				cout<<*(it-1)<<endl;
				break;
			}
		}
	}
	return 0;
}
*/

/*
题目描述：
输入正整数n，，其中a~j恰好为0~9的一个排列，2<=n<=79.

输入：
输入正整数n

输出：
按从小到大的顺序输出所有形如abcde / fghij = n的表达式，注意开头是0也要输出

样例输入
62
样例输出
79546/01283=62
94736/01528=62

#include<stdio.h> 
#include<bits/stdc++.h> 
#include<set>
using namespace std;
vector<int>v;
vector<int>::iterator it;
set<int>SE;
int N(int a)
{
	while(a)
	{
		SE.insert(a%10);
		a/=10;
	}
//	cout<<SE.size()<<endl;
	return SE.size();
}
int main()
{
	int n;cin>>n;
	for(int i=1234;i<=9876;i++) //除数 
	{
		if(i*n>=12345&&i*n<=98765)//被除数也一定是5位数 
		{
			SE.clear();
			if(N(i*n)==5&&N(i)==10) 
				printf("%d/%05d=%d\n",i*n,i,n);
			else{
				SE.clear();
				if( N(i*n)==5&&N(i)==9&&*SE.begin()==1) 
				printf("%d/%05d=%d\n",i*n,i,n);
			}			
		}
	} 	
}
*/

