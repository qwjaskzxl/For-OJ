/*
题目描述：
一座很长的畜栏，包括N (2 <= N <= 100,000)个隔间，
这些小隔间依次编号为x1,…,xN (0 <= xi <= 1,000,000,000).
但是，John的C (2 <= C <= N)头牛们并不喜欢这种布局，
而且几头牛放在一个隔间里，
他们就要发生争斗。为了不让牛互相伤害。
John决定自己给牛分配隔间，使任意两头牛之间的最小距离尽可能的大，
那么，这个最大的最小距离是什么呢？

输入：
有多组测试数据，以EOF结束。 第一行：空格分隔的两个整数N和C 第二行——第N+1行：分别指出了xi的位置

输出：
每组测试数据输出一个整数，满足题意的最大的最小值，注意换行。

样例输入
5 3
1
2
8
4
9
样例输出
3
*/

//直接选出所有组合，然后排序。。在选最大的Min 
#include<iostream>
#include<string.h>
#include<set>
using namespace std;
set<int>SE;
set<int>::iterator it;
int n,m;
unsigned long long Map[100005],vst[100005];
unsigned long long a[100005],Max=0;
void C(int x)
{
	if(x==m)//注意从0开始就是等于了 
	{		
		SE.clear();
		for(int i=0;i<m;i++)
			SE.insert(Map[a[i]]);						
		int Min=99999;
		for(it=SE.begin(); ++it!=SE.end(); )//这这里就没写++了 
			{
				it--;
				int a1=*it, a2=*++it;
				if(Min>a2-a1) Min=a2-a1;				
			}
		if(Min>Max) Max=Min;
		return ;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!vst[i]) 
		{		
			a[x]=i;
			if(a[x]<a[x-1]) continue;
			vst[i]=1;
			C(x+1);
			vst[i]=0; 
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>Map[i];
	memset(vst,0,sizeof(vst));
	C(0);
	cout<<Max;
}

//POJ 上要用 二分枚举才能不TLE 
#include<stdio.h>    
#include<stdlib.h>  
#include<algorithm>   
using namespace std;   
int a[100005],n,c;    
int judge(int mid)    
{    
    int i,count=1,t=a[0]; //count是指放了几头牛，从1开始。t用来表示当前的房间号  
    for(i=1;i<n;i++)  
    {  
        if(a[i]-t>=mid)//判断两个房间之间的距离   
        {    
            count++;  
            t=a[i];//修改t的值，即修改当前房间号，例如原来t=1,a[2]=4,若a[2]-t>=mid符合，那么t=4,然后算a[3]或者a[4]与t之间的距离。    
            if(count>=c)//可以放下C头牛    
                return 1;
        }  
    }    
    return 0;  
}    
int binary()//二分搜索符合条件的最小距离的最大值    
{    
    int low=0,high=a[n-1]-a[0],mid;    
    while(low<=high)    
    {    
        mid=(low+high)/2;//mid即为最小房间号与最大房间号之间的距离    
        if(judge(mid))   
            low=mid+1; //所求距离>=mid，可以继续增大试探   
        else    
            high=mid-1;//所求距离<mid，所以必须减小来试探    
    }    
    return low-1; //由于在之前距离+1，所以此时-1   
}     
int main()    
{    
    while(~scanf("%d%d",&n,&c))    
    {    
        int i;    
        for(i=0;i<n;i++)    
            scanf("%d",&a[i]);    
        sort(a,a+n);
        printf("%d\n",binary());    
    }    
    return 0;    
}   
