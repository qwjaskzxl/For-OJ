/*
读入两个小于10000的正整数A和B，计算A+B。
要注意的是：如果A和B的末尾K（不超过8）位数字相同，请直接输出-1。 
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()//我16:44->16:49
{
	int a,b,k;
	while(cin>>a>>b>>k)
	{
		if(!a&&!b) break;
		int p=pow(10,k);
		if(a%p!=b%p)
		printf("%d\n", a+b);
		else printf("-1\n");
	}
	return 0;
}

/*
比如25的平方是625，低位部分是25，因此25是一个守形数。
编一个程序，判断N是否为守形数。
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()//我16:53->16:57
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		int t=n,m=0;//m为多少位 
		while(t>0)
		{
			t/=10;m++;
		}
		int k=pow(10,m);
		if(n*n%k==n) printf("Yes!\n");
		else printf("No!\n");
	}
	return 0;
}
