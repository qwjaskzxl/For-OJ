/*
��������С��10000��������A��B������A+B��
Ҫע����ǣ����A��B��ĩβK��������8��λ������ͬ����ֱ�����-1�� 
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()//��16:44->16:49
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
����25��ƽ����625����λ������25�����25��һ����������
��һ�������ж�N�Ƿ�Ϊ��������
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()//��16:53->16:57
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		int t=n,m=0;//mΪ����λ 
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
