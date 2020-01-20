#include<iostream>
#include<algorithm>
using namespace std;
struct S
{
	double j,f;//收获，代价
} s[1005];
int cmp(S a,S b)
{
	return a.j/a.f > b.j/b.f;//降序，每次选最大的
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n) && (m!=-1&&n!=-1))//这样只要一行 
	{
		for(int i=0; i<n; i++)
			cin>>s[i].j>>s[i].f;
		sort(s,s+n,cmp);

		int i=0;
		double sum=0;
		while(m>0&&i<n)//自己m用完了，或对方没有能换的了，两种情况都要终止
		{
			if(m-s[i].f>0.001)//浮点数要这样判断大小！
			{
				m-=s[i].f;
				sum+=s[i].j;
				i++;
			}
			else
			{
				sum+=m/s[i].f*s[i].j;
				m=0;
			}
		}
		printf("%.3lf\n",sum);//double是lf
	}
	return 0;
}
