#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>>q;//С���� 
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		while(!q.empty()) q.pop();//��ʵ�����ʣһ������Ҳ����ÿ��case��ĩβpop
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			q.push(x);
		}
		int ans=0;
		while(q.size()>1)//���ʣ��һ����so��1��Ԫ��ʱ��ֹ 
		{
			int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();			
			q.push(a+b);
			ans+=a+b;//��ÿ���м�����Ӿ��� ��Ȩ·����
		}
		printf("%d\n", ans);
	}
	return 0;
}
