#include<bits/stdc++.h> 
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iostream> 
#include<cmath>
#include<algorithm> 
#include<vector>
#include<set>
using namespace std;
set<int>SE,SE1;
int F(int n)
{
	int t=0;
	while(n)
	{
		if(SE.count(n%10)) return 0;
		SE.insert(n%10);
		n/=10;
		t++;
	}
	return t;
}

int F1(int n)
{
	int t=0;
	while(n)
	{
		if(SE.count(n%10)) t++;
		SE.insert(n%10);
		SE1.insert(n%10);
		n/=10;
//		t++;
	}
	return t;
}
int main()
{
	int sum=0;
	for(int i=1;i<=999;i++)
	{
		for(int j=1;j<=999;j++)
		{
			SE.clear();
			SE1.clear();		
			if(F(i)&&F(j)&&SE.size()==4 && F1(i*j)==4)
			{			
				if(SE1.size()==4) 
//				cout<<i<<'*'<<j<<'='<<i*j<<' '<<++sum<<endl;
				sum++;
			}
		}
	}
	cout<<sum/2;
}


//int main()
//{
//int i,j,sum,k;
//char s1[4], s2[4],s3[6];
//for(i=1;i<=999;i++) //��������ˣ�����һ���ض�������4λ��
//{
//for(j=1;j<=999;j++)
//{
//sum=i*j;
//if(sum>=1000&&sum<=9999&&i<j) //ȷ���˻���һ����λ��
//{
//sprintf(s3,"%d",sum); //�ѳ˻�ת��Ϊ�ַ�����������
//sort(s3,s3+4);         
//k=1;
//for(;k<4;k++) //�жϳ˻��ִ��е���������ͬ
//{
//if(s3[k-1]==s3[k])
//break;
//}
//if(k==4)       //����˻������ĸ���ͬ���������
//{
//sprintf(s1,"%d",i); //�ѵ�һ����ת��Ϊ�ִ�
//sprintf(s2,"%d",j); //�ѵڶ�����ת��Ϊ�ִ�
//strcat(s1,s2);      //�������ִ��ϲ�Ϊһ��
//sort(s1,s1+4);      //����
//if(strcmp(s1,s3)==0) //�Ƚ������ִ��Ƿ���ͬ�������ͬ�����
//printf("%d * %d = %d\n",i,j,sum);
//
//}
//}
//}
//}
//return 0;
//}
