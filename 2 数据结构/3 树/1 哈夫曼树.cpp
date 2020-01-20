#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>>q;//小顶堆 
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		while(!q.empty()) q.pop();//其实是最后剩一个数，也可在每个case的末尾pop
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			q.push(x);
		}
		int ans=0;
		while(q.size()>1)//最后剩下一个，so到1个元素时终止 
		{
			int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();			
			q.push(a+b);
			ans+=a+b;//把每个中间结果相加就是 带权路径和
		}
		printf("%d\n", ans);
	}
	return 0;
}
