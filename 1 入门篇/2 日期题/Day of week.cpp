#include<bits/stdc++.h>
using namespace std;

string week[7]={"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};

int month[13][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,
				  31,31,31,31,30,30,31,31,30,30,31,31};//1表示闰年 
int y=0,m=0,d=0;
string mm;
#define is_r(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0 //简洁写法 

int calcu_day(int y, int m, int d)
{
	int sum=0;
	if(is_r(y)) {
		for(int i=1;i<m;i++)
		sum+=month[i][1];
	}
	else{
		for(int i=1;i<m;i++)
		sum+=month[i][0];
	}
	sum+=d;
	return sum;
}
int days_y(int y)
{
	if(is_r(y)) return 366;
	else return 365;
}

int main()
{
	
	while(cin>>d>>mm>>y)
	{

	for(int i=0;i<12;i++)
	{
		if(months[i]==mm)
		{
			m=i+1;
			break;
		}
	}

	int sum=0;	
	for(int i=0;i<y; i++)//算year。不算首尾的年
	{
		sum+=days_y(i);
	} 
	
	sum+=calcu_day(y,m,d);
	cout<<week[sum%7]<<'\n';
	}
	
	return 0;
}

/*
21 12 2012
5 1 2013
*/
 
