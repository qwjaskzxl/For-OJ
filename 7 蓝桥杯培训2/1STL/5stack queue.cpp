/*
#include <bits/stdc++.h> 
#include <queue> 
using namespace std;
queue<int>q;
int main()
{
	int n;cin>>n;
	int a,b;
	while(n--)
	{
		cin>>a;
		if(a==1){
			cin>>b;
			q.push(b);
		}
		else if(a==2){
			if(q.size()==0) cout<<"no";
			else{
				cout<<q.front()<<endl; 
				q.pop();
			}			
		}
		else{cout<<q.size()<<endl;}
	}
}
*/


/*
题目描述：
某部队进行新兵队列训练，将新兵从一开始按顺序依次编号，并排成一行横队，训练的规则如下：从头开始一至二报数，凡报到二的出列，剩下的向小序号方向靠拢，再从头开始进行一至三报数，凡报到三的出列，剩下的向小序号方向靠拢，继续从头开始进行一至二报数。。。，以后从头开始轮流进行一至二报数、一至三报数直到剩下的人数不超过三人为止。

输入：
本题有多个测试数据组，第一行为组数N，接着为N行新兵人数，新兵人数不超过5000。

输出：
共有N行，分别对应输入的新兵人数，每行输出剩下的新兵最初的编号，编号之间有一个空格。

样例输入
2
20
40
样例输出
1 7 19
1 19 37
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>::iterator it;
int main()
{
	int n;cin>>n;
	int a;
	while(n--)
	{
		cin>>a;
		for(int i=1;i<=a;i++) v.push_back(i);	
		int t=1;		
		while(v.size()>3) 
		{
			it=v.begin();
			
			if(t%2){
				int p=v.size()/2;//控制删除个数 
				for(int i=1;i<=p;i++) v.erase(it+i);//一个一个动态删除，所以要找规律										
			} 
			else {
				int p=v.size()/3;
				for(int i=2;i<=2*p;i+=2) v.erase(it+i);
			}
			t++;
		}		
		for(it=v.begin();it!=v.end()-1;it++) //可能只有两个甚至一个 
			cout<<*it<<' ';
		cout<<*it;
		cout<<endl;
		v.clear();
	}
}

