/*
��Ŀ������
��ͯ��������KλС���ѵ�С�������͡�С���ó�����ص��ɿ����д�С�����ǡ� С��һ����N���ɿ��������е�i����Hi x Wi�ķ�����ɵĳ����Ρ� Ϊ�˹�ƽ�����С����Ҫ���� N ���ɿ������г�K���ɿ����ָ�С�����ǡ��г����ɿ�����Ҫ���㣺 1. ��״�������Σ��߳�������
2. ��С��ͬ
����һ��6x5���ɿ��������г�6��2x2���ɿ�������2��3x3���ɿ����� ��ȻС�����Ƕ�ϣ���õ����ɿ��������ܴ����ܰ�СHi��������ı߳��Ƕ���ô��

���룺
��һ�а�����������N��K��(1 <= N, K <= 100000) ����N��ÿ�а�����������Hi��Wi��(1 <= Hi, Wi <= 100000) ���뱣֤ÿλС���������ܻ��һ��1x1���ɿ�����

�����
����г����������ɿ��������ܵı߳���

��������
2 10
6 5
5 6
�������
2
*/

#include<bits/stdc++.h>
using namespace std;
int h[100000],w[100000];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>h[i]>>w[i];
	}
	int Sum=99999,j;
	for(j=1;Sum>=k;j++)
	{
		Sum=0;
		for(int i=0;i<n;i++)
		{
			int a=h[i]/j;
			int b=w[i]/j;
			Sum+=a*b;	
		}
	}
	cout<<j-2;
}


//����ö�ٷ���Ч�ʸ��� 

//#include<stdio.h>  
//int n,k,h[100010],w[100010];  
//bool solve(int n)  
//{  
//    int res=0,a,b,i;  
//    for(i=0;i<n;i++)  
//    {  
//        a=h[i]/n;  
//        b=w[i]/n;  
//        res+=a*b;  
//    }  
//    if(res>=k)  
//        return true;  
//    return false;  
//}  
//int main()  
//{  
//    int i,low,high;  
//    while(scanf("%d%d",&n,&k)!=EOF)  
//    {  
//        low=1;  
//        high=10000;  
//        for(i=0;i<n;i++)  
//            scanf("%d%d",&h[i],&w[i]);  
//        while(low<high-1)  
//        {  
//            int mid=(low+high)/2;  
//            if(!solve(mid))  
//                high=mid;  
//            else  
//                low=mid;  
//        }  
//        printf("%d\n",low);  
//    }  
//    return 0;  
//}  
