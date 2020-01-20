#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
	int n;
	//scanf("%d",&n)!=EOF或者写cin>>n 都能AC 
	while(scanf("%d",&n)!=EOF)//之前不小心写成NULL或者不加。就输出超限？？？ 
	{

		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a,a+n);
		cout<<a[n-1]<<endl;

		if(n==1)
		{
			cout<<-1<<endl;//忘记换行 。。 
			continue;
		}
		for(int i=0; i<n-1; i++)
		{
			//if(a[i]!=a[n-1])//为什么写上是错的啊？？ 
				printf("%d ",a[i]);
		}
		cout<<endl;
	}
	return 0;
}
