#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
	int n;
	//scanf("%d",&n)!=EOF����дcin>>n ����AC 
	while(scanf("%d",&n)!=EOF)//֮ǰ��С��д��NULL���߲��ӡ���������ޣ����� 
	{

		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a,a+n);
		cout<<a[n-1]<<endl;

		if(n==1)
		{
			cout<<-1<<endl;//���ǻ��� ���� 
			continue;
		}
		for(int i=0; i<n-1; i++)
		{
			//if(a[i]!=a[n-1])//Ϊʲôд���Ǵ�İ����� 
				printf("%d ",a[i]);
		}
		cout<<endl;
	}
	return 0;
}
