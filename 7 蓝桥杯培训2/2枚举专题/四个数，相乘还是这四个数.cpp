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
//for(i=1;i<=999;i++) //两个数相乘，其中一个必定不超过4位数
//{
//for(j=1;j<=999;j++)
//{
//sum=i*j;
//if(sum>=1000&&sum<=9999&&i<j) //确定乘积是一个四位数
//{
//sprintf(s3,"%d",sum); //把乘积转换为字符串，并排序
//sort(s3,s3+4);         
//k=1;
//for(;k<4;k++) //判断乘积字串中的数都不相同
//{
//if(s3[k-1]==s3[k])
//break;
//}
//if(k==4)       //如果乘积是由四个不同的数字组成
//{
//sprintf(s1,"%d",i); //把第一个数转换为字串
//sprintf(s2,"%d",j); //把第二个数转换为字串
//strcat(s1,s2);      //把两个字串合并为一个
//sort(s1,s1+4);      //排序
//if(strcmp(s1,s3)==0) //比较两个字串是否相同，如果相同则输出
//printf("%d * %d = %d\n",i,j,sum);
//
//}
//}
//}
//}
//return 0;
//}
