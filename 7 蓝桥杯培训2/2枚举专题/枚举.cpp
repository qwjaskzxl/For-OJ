/*
����Ļ����22ʱ����Ļش�Ӧ��23������Ļ����8ʱ����Ļش�Ӧ��7����X��������������ش�X;����ӽ�X������������ʱ����ش��������������

���룺
��һ�У�N Ҫ���µ��������� ��������N�У�ÿ����һ��������X 1<=N<=5 1<=X<=1000

�����
�����N�У�ÿ���Ƕ�ӦX����ӽ���������

��������
4
22
5
18
8
�������
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
	for(int i=3;i<=1000;i+=2) //��2֮���ż������������ 
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
��Ŀ������
����������n��������a~jǡ��Ϊ0~9��һ�����У�2<=n<=79.

���룺
����������n

�����
����С�����˳�������������abcde / fghij = n�ı��ʽ��ע�⿪ͷ��0ҲҪ���

��������
62
�������
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
	for(int i=1234;i<=9876;i++) //���� 
	{
		if(i*n>=12345&&i*n<=98765)//������Ҳһ����5λ�� 
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

