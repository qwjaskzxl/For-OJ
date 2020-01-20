#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[10000];

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,v,w;
		cin>>n>>v>>w;
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a,a+n);
		
		int v2=0;//新体积 
		double w2=0.00;//新浓度 
		for(int i=0; i<n; i++)
		{
			double t=(v*a[i] + v2*w2)/(v2+v);
			if(t<w&&fabs(t-w)>1e-8 || fabs(t-w)<1e-8)//注意浮点数比较问题 
			{
				w2=(v*a[i] + v2*w2)/(v2+v);//现有浓度 混合 新加浓度
				v2+=v;
			}
			else break;//记得break，虽然已sort不会出现后面 浓度ok的情况，但这样节约运算 
		}
		printf("%d %.2lf\n", v2,w2/100);
	}
	return 0;
}
/*
3
1 100 10
100
2 100 24
20 30
3 100 24
20 20 30
*/
