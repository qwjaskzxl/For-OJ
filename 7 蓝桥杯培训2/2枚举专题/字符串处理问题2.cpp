/*
��Ŀ������
����Ħ˹��X���յ�һ�����ϣ�ȫ����Сд��ĸ��ɡ�
���������ṩ����һ�����ϣ���೤��Ϊ8�������б�
����Ħ˹���֣���Щ�����Ǳ����Һ���������ǰ�Ƿ������еġ�
�����дһ�����򣬴ӵ�һ�������������������������λ�á�
Ҫ����������������п����ԡ�

���룺
�����һ�У�һ���ַ���s��ȫ����Сд��ĸ��ɣ�����С��1024*1024
������һ����һ������n,��ʾ������n�����룬1<=n<=1000
��������n���ַ���������Сд��ĸ��ɣ����ȶ�Ϊ8

�����
һ������, ��ʾÿ�����������������s��ƥ��������ܺ͡�

��������
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc
�������
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
	for(int i=0;i<=S0.length()-8;i++) //���ϵȺ� 
	{
		S.push_back(S0.substr(i,8));//��ȡ��ʼλ�ã����� 
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
//��һ�֣�ֱ�ӶԱ��������У�����Ч��̫�� 
//		do
//		{
//			string b=a;
////			cout<<b<<endl;			
//			if(count(S.begin(),S.end(),b)) sum++;
//		}while(next_permutation(a,a+8));

//�ڶ��֣�����׼������Ƚ��Ƿ���� 
//		for(int i=0;i<S.size();i++)
//		{
//			string a1=a;
//			string b=S[i];
//			sort(b.begin(),b.end());
//			if(a1==b) sum++;
//		}
//�����֣�����Ԫ�ظ�����ȼ��� ���õ�set��������tle�� 
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
//	for(int i=0;i<=S0.length()-8;i++) //���ϵȺ� 
//	{
//		S.push_back(S0.substr(i,8));//��ȡ��ʼλ��,���� 
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



//AC���룡 
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

    scanf("%s", str);//��Ϊ����ͱ�ʾ�׵�ַ 
    len=strlen(str);
    for(i=0; i<=len-8; i++) //�ֳɳ���Ϊ8����ô��Σ�����һ����ά���� N*26 
        for(j=i; j<=i+7; j++) //����ֵ��ϳ��ֵĴ��� 
            a[i][str[j]-'a']+=1;
    
    scanf("%d",&n);
    sum=0;
    for(k=0; k<n; k++)
    {
        int flag;
        memset(b,0,sizeof(b));

        scanf("%s",s);//���Ⱦ���8 
        for(i=0; i<8; i++)
            b[s[i]-'a']+=1;

        for(i=0; i<=len-8; i++)
        {
            flag=1;
            for(int j=0; j<26; j++) //ֱ�ӱȸ�����ֵĴ������� 
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
