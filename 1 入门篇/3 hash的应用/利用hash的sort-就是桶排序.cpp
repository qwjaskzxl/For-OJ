/*
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005];

int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		for(int i=0;i<m;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}
*/

//����д����ʵ���ܳ�ʱ�ģ���Ϊlog2 1e6=19.931569���ܹ�����2e7������Ҳû��ʱ��
//������hash������ֻҪO(n)�ĸ��Ӷ�
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1000005];

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(a,0,sizeof(a));//�������� winit
		for(int i=0; i<n; i++)
		{
			int x;
			cin>>x;
			a[x+500000]=1;
		}
		for(int i=1000000,j=0; i>=0 && j<m; i--)
		{
			if(a[i])
			{
				cout<<i-500000<<' ';
				j++;
			}
		}
		cout<<endl;
	}
	return 0;
}
