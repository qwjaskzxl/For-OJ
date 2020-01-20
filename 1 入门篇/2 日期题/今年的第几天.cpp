#include<iostream>
using namespace std;
#define is_r(x) x%100!=0 && x%4==0 || x%400==0 ?1:0
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int y,m,d;
	while(scanf("%d %d %d", &y,&m,&d)!=EOF)
	{
		int sum=0;
		if(is_r(y)) month[2]=29;
		else month[2]=28;
		for(int i=1;i<m;i++)
			sum+=month[i];
		sum+=d;
		printf("%d\n", sum);
	}
	return 0;
}
