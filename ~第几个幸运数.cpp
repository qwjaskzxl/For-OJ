到x星球旅行的游客都被发给一个整数，作为游客编号。
x星的国王有个怪癖，他只喜欢数字3,5和7。
国王规定，游客的编号如果只含有因子：3,5,7,就可以获得一份奖品。

我们来看前10个幸运数字是：
3 5 7 9 15 21 25 27 35 45
因而第11个幸运数字是：49

小明领到了一个幸运数字 59084709587505，他去领奖的时候，人家要求他准确地说出这是第几个幸运数字，否则领不到奖品。
请你帮小明计算一下，59084709587505是第几个幸运数字。
需要提交的是一个整数，请不要填写任何多余内容。
和《算法竞赛入门经典（第二版）》中的丑数例题类型一样。
我使用了优先队列与集合解决

#include<cstdio>
#include<iostream>
#include<queue>
#include<set>
#include<vector>
 
using namespace std;
 
typedef long long LL;
 
priority_queue<LL, vector<LL>, greater<LL> > num;
set<LL> n;
int ans = -1;
 
int main()
{
	num.push(1);
	n.insert(1);
	while(!n.count(59084709587505 * 7))
	{
		LL temp = num.top();
		num.pop();
		ans++;
		for(int i = 3; i <= 7; i += 2)
		{
			LL number = temp * i;
			if(!n.count(number))
			{
				num.push(number);
				n.insert(number);
			}
		}
	} 
	cout << ans <<endl;
	return 0;
} 
运行结果 ： 1905
