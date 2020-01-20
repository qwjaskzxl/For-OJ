#include<iostream>
using namespace std;
#define is_r(x) x%400==0 || x%100!=0 && x%4==0 ?1:0
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int y,d;
	while(scanf("%d %d",&y, &d)!=EOF)
	{
		int m=1;
		if(is_r(y)) month[2]=29;
		else month[2]=28;
		for(int i=1;i<13 && d>=month[i];i++)
		{
			d-=month[i];
			m++;
		}		
		printf("%04d-%02d-%02d\n",y,m,d);
	}
	return 0;
}
