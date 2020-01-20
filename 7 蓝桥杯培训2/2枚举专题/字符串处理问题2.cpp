/*
题目描述：
福尔摩斯从X星收到一份资料，全部是小写字母组成。
他的助手提供了另一份资料：许多长度为8的密码列表。
福尔摩斯发现，这些密码是被打乱后隐藏在先前那份资料中的。
请你编写一个程序，从第一份资料中搜索可能隐藏密码的位置。
要考虑密码的所有排列可能性。

输入：
输入第一行：一个字符串s，全部由小写字母组成，长度小于1024*1024
紧接着一行是一个整数n,表示以下有n行密码，1<=n<=1000
紧接着是n行字符串，都是小写字母组成，长度都为8

输出：
一个整数, 表示每行密码的所有排列在s中匹配次数的总和。

样例输入
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc
样例输出
4
*/

/*
#include<bits/stdc++.h> 
#include<vector>
#include<map>
#include<set>
using namespace std;
vector<string>S;
map<char,int>Map1,Map2; 
set<char>SE;
set<char>::iterator it;
string S0;
int cmp(char a,char b)
{
	return a<b;
}
int main()
{
	cin>>S0;
	for(int i=0;i<=S0.length()-8;i++) //加上等号 
	{
		S.push_back(S0.substr(i,8));//截取起始位置，长度 
	}
//	for(int i=0;i<S.size();i++)
//	{
//		cout<<S[i]<<endl;
//	}
//	cout<<S.size();
	int n;cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		char a[9];cin>>a;
//		sort(a,a+8,cmp);	
//第一种：直接对比所有排列，但是效率太低 
//		do
//		{
//			string b=a;
////			cout<<b<<endl;			
//			if(count(S.begin(),S.end(),b)) sum++;
//		}while(next_permutation(a,a+8));

//第二种：“标准化”后比较是否相等 
//		for(int i=0;i<S.size();i++)
//		{
//			string a1=a;
//			string b=S[i];
//			sort(b.begin(),b.end());
//			if(a1==b) sum++;
//		}
//第三种：所有元素个数相等即可 ，用的set。。还是tle了 
		for(int i=0;i<S.size();i++)
		{
			string a1=a;
			string b=S[i];	
			SE.clear();		
			for(int j=0;j<8;j++)
			{					
				SE.insert(a1[j]);					
//				if(!Map1.count(a1[j])) Map1[a1[j]]=0;
//				Map1[a1[j]]++;	
//				if(!Map2.count(b[j])) Map2[b[j]]=0;
//				Map2[b[j]]++;		
			}	
			int t=1;
			for(it=SE.begin();it!=SE.end();it++)
			{
				if(count(a1.begin(),a1.end(),*it)!=count(b.begin(),b.end(),*it))
				{
					t=0; break;
				}
			}
			if(t) sum++;			
		}
	}
	cout<<sum;
    return 0;
}

*/

//#include <bits/stdc++.h> 
//#include<vector>
//#include<map>
//#include<set>
//using namespace std;
//vector<string>S;
//map<char,int>Map1,Map2; 
//set<char>SE;
//set<char>::iterator it;
//string S0;
//int main()
//{
//	cin>>S0;
//	for(int i=0;i<=S0.length()-8;i++) //加上等号 
//	{
//		S.push_back(S0.substr(i,8));//截取起始位置,长度 
//	}
//	int n;cin>>n;
//	int sum=0;
//	for(int i=0;i<n;i++)
//	{
//		char a[9];
//		SE.clear();	
//		for(int j=0;j<=8;j++)
//		{
//			scanf("%c",&a[j]);
//			SE.insert(a[j]);	
//		}
////		cin>>a;
//		for(int i=0;i<S.size();i++)
//		{
//			string a1=a;
////			cout<<a<<endl;
//			int t=1;
//			for(it=SE.begin();it!=SE.end();it++)
//			{
//				if(count(a1.begin(),a1.end(),*it)!=count(S[i].begin(),S[i].end(),*it))
//				{
//					t=0; break;
//				}
//			}
//			if(t) sum++;				
//		}
//	}
//	cout<<sum;
//    return 0;
//}



//AC代码！ 
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char str[1024*1024+10],s[10];
int  a[1024*1024+10][26],b[26];

int main()
{
    int n,sum;
    int len,len2;
    int i,j,k;
    memset(a,0,sizeof(a));

    scanf("%s", str);//因为本身就表示首地址 
    len=strlen(str);
    for(i=0; i<=len-8; i++) //分成长度为8的这么多段，想象一个二维数组 N*26 
        for(j=i; j<=i+7; j++) //标记字典上出现的次数 
            a[i][str[j]-'a']+=1;
    
    scanf("%d",&n);
    sum=0;
    for(k=0; k<n; k++)
    {
        int flag;
        memset(b,0,sizeof(b));

        scanf("%s",s);//长度就是8 
        for(i=0; i<8; i++)
            b[s[i]-'a']+=1;

        for(i=0; i<=len-8; i++)
        {
            flag=1;
            for(int j=0; j<26; j++) //直接比各项出现的次数就行 
            {
                if(a[i][j]!=b[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                sum++;
        }
    }
	cout<<sum;
}
