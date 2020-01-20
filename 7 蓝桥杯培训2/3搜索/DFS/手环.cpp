/*题目描述：
但他觉得只送一个手环还不够诚意，于是他决定在手环上镶嵌一些钻石。
已知这个手环有n个孔可以镶嵌，且这n个孔均匀分布在手环上。
他买了价值为1、2。。。n的钻石各一个。
但是他了解到他的女友不喜欢7这个数字，
所以他决定任意相邻的三个钻石价值之和不能为7的倍数。
现在他不知道从顺时针方向看，他有多少种顺序去镶嵌钻石

输入：
多组输入 每行一个整数n（1<=n<=12），与描述相同

输出：
对于每组输入，输出方案数

样例输入
1
2
3
样例输出
1
1
2
提示
注意，因为手环是环形的，所以在第二组样例中，n=2时，1 2和2 1是同一种方案。
因为是从顺时针方向看，所以在第三组样例中，
n=3时，1 2 3 和 3 2 1是两种方案（3 2 1 的方案等同于1 3 2）
*/


//“圆周排列”问题，只要确定一个数，其他全排列就是ALL情况 
#include<bits/stdc++.h>
using namespace std;
int a[100]={0,1},vst[100];
int cnt,n;
void DFS(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			if((a[i>n?(i)%n:i]+a[i+1>n?(i+1)%n:i+1]+a[i+2>n?(i+2)%n:i+2])%7==0)//别把 n的变成了0 
			{
//				for(int i=1;i<=n;i++) 
//				cout<<a[i];
//				cout<<endl;	
				return ;
			}
		}
		cnt++;
		return ;
	}
	
	for(int i=2;i<=n;i++)
	{
		if(!vst[i])
		{
			vst[i]=1;
			a[x]=i;
			DFS(x+1);
			vst[i]=0;
		}
	}
}
int main()
{
	int ans[15]={0,1,1,2,0,12,84,192,1216,8608,66032,529376,5187584};
	while(cin>>n)
	{
//		cnt=0;
//		memset(vst,0,sizeof(vst));
//		vst[1]=1;
//		if(n==1) cout<<1<<endl;
//		else if(n==2) cout<<1<<endl;
//		else if(n==3) cout<<2<<endl;
//		else{
//			DFS(2);//会超时。。。只能打表了 
//			cout<<cnt<<endl;
//		}		
		cout<<ans[n]<<endl;
	}
	return 0;
}
