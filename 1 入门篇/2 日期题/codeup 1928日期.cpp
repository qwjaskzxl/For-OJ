#include<iostream>
using namespace std;
int month[13][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,
				  31,31,31,31,30,30,31,31,30,30,31,31};//1��ʾ���� 
int ay=0,am=0,ad=0,by=0,bm=0,bd=0;
string x,y;//��ʵ����ֱ�Ӵ� intȻ����ȡ������ģ������� 

#define is_r(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0 //���д�� 
void s2i()
{
	for(int i=0;i<4;i++)
		ay=ay*10+x[i]-'0';
	for(int i=4;i<6;i++)
		am=am*10+x[i]-'0';
	for(int i=6;i<8;i++)
		ad=ad*10+x[i]-'0';
	for(int i=0;i<4;i++)
		by=by*10+y[i]-'0';
	for(int i=4;i<6;i++)
		bm=bm*10+y[i]-'0';
	for(int i=6;i<8;i++)
		bd=bd*10+y[i]-'0';
}
/*
int is_r(int y)
{
	if(y%400==0 || y%100!=0 && y%4==0)//ע�������ǡ��� 
		return 1;
	return 0;
}
*/
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
	cin>>x>>y;
	if(x>y)//�и��ӣ��п��ܵ�һ���ȵڶ���������Ҫ����
	{
		string t=x;
		x=y;
		y=t;
	}
	s2i();
	
	int sum=0;	
	for(int i=ay+1; i<by; i++)//��year��������β����
	{
		sum+=days_y(i);
	} 
	if(ay!=by)//��β����ͬһ�� 
	{
		sum+=days_y(ay)-calcu_day(ay,am,ad);
		sum+=calcu_day(by,bm,bd);
	}
	else {
		sum+=calcu_day(by,bm,bd) -calcu_day(ay,am,ad);
	}
	cout<<sum+1<<endl;
	return 0;
}

/*
20200201
00040101

10091231
20120101

20110101
20110302
20120101
20120302
20120101
*/
 
