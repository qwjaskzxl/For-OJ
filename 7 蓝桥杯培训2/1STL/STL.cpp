#include <bits/stdc++.h> 
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iostream> 
#include<cmath>
#include<algorithm> 
#include<vector>
#include<map>
using namespace std;
class node{
	private:
		int d2[3];
	public:
}N[3];
vector<string>v;//������	
vector<int>::iterator it;//������ 
map<string,int>m;
int cmp(string a,string b) //����Ϊ<> ������� 
{
	return m[a]<m[b];
}
int main()
{
	int n;cin>>n;
	string a;
	for(int i=0;i<n;i++) 
	{
		cin>>a;
		if(!count(v.begin(),v.end(),a)) 
			v.push_back(a);	
	} 
//	cin>>a;
//	sort(v.begin(),v.end(),cmp);
//	for(int i=0;i<v.size();i++)
}
