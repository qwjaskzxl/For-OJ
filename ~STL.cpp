#include<bits/stdc++.h>
#include<vector>
#include<set> 
using namespace std;

int vec()//only vector and string can use 迭代器+数字 
{
	vector<int>v;
	vector<int>:: iterator it;
	int a=1;
	v.push_back(a);
	v.pop_back();//删除最后一个 
	cout<<v.size();
	v.clear();
	it=v.begin()+1;
	v.insert(it,a);
	v.erase(v.begin(),v.end());//[1st,last)
}

int sett()
{
	set<int>se;
	int a=1;
	se.insert(a);
	se.find(a);
	se.erase(a);//删除值 
	se.erase(se.begin(),se.end());//删除区区间 
}

int main()
{
	string s="qwe";
	cout<<s.substr(1,2)<<' ';//返回1开始，长度为2的子串
	cout<<s.find("we");//返回1st找到的位置 
	
	return 0;
}
