#include<iostream>
#include<string.h>
using namespace std;
int L[10005];

int main()
{
	int l,m;//马路长度，区间数 
	while(cin>>l>>m)
	{
		if(!l&&!m) break;
		memset(L,0,sizeof(L));
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			for(int j=a;j<=b;j++)
			{
				L[j]=1;
			}
		}
		int sum=0;
		for(int i=1;i<=l;i++)
		{
			if(L[i]==0) sum++;
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
