/*
题目描述：
现在小学的数学题目也不是那么好玩的。 看看这个寒假作业：

□ + □ = □

□ - □ = □

□ × □ = □

□ ÷ □ = □

每个方块代表1~13中的某一个数字，但不能重复。 比如： 6 + 7 = 13 9 - 8 = 1 3 * 4 = 12 10 / 2 = 5

以及： 7 + 6 = 13 9 - 8 = 1 3 * 4 = 12 10 / 2 = 5

就算两种解法。（加法，乘法交换律后算不同的方案）

你一共找到了多少种方案？

输入：
输出：
请填写表示方案数目的整数。
*/
#include<bits/stdc++.h>
using namespace std;
int n=13,m=12,cnt=0;
int a[15],vst[15]; 
void C(int x)
{
	if(x>m)
	{	
//		for(int i=1;i<=m;i++)
//			cout<<a[i]<<' ';
//		cout<<endl;
		cnt++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			a[x]=i;
			if(x>=3&&a[1]+a[2]!=a[3]) continue;
			if(x>=6&&a[4]-a[5]!=a[6]) continue;	
			if(x>=9&&a[7]*a[8]!=a[9]) continue;
			if(x>=12&&a[10]!=a[11]*a[12]) continue;//除法要变乘法 ！！				
			vst[i]=1;
			C(x+1);
			vst[i]=0;
		}
	}
}
int main()
{
	memset(a,0,sizeof(a));
	memset(vst,0,sizeof(vst));
	C(1);
	cout<<cnt;
}
