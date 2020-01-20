#include<iostream>
#include<string.h>
using namespace std;
int N[10000];
int M[205];

int main()
{
	int n,m;
	cin>>n>>m;
	memset(M,0,sizeof(M));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&N[i]);
		M[N[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(M[N[i]]>=2)
			printf("%d\n",M[N[i]]-1);//¼õÈ¥×Ô¼º 
		else printf("BeiJu\n");
	}
	return 0;
}
