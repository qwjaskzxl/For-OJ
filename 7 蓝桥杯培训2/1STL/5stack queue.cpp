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
��Ŀ������
ĳ���ӽ����±�����ѵ�������±���һ��ʼ��˳�����α�ţ����ų�һ�к�ӣ�ѵ���Ĺ������£���ͷ��ʼһ�������������������ĳ��У�ʣ�µ���С��ŷ���£���ٴ�ͷ��ʼ����һ�������������������ĳ��У�ʣ�µ���С��ŷ���£��������ͷ��ʼ����һ�����������������Ժ��ͷ��ʼ��������һ����������һ��������ֱ��ʣ�µ���������������Ϊֹ��

���룺
�����ж�����������飬��һ��Ϊ����N������ΪN���±��������±�����������5000��

�����
����N�У��ֱ��Ӧ������±�������ÿ�����ʣ�µ��±�����ı�ţ����֮����һ���ո�

��������
2
20
40
�������
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
				int p=v.size()/2;//����ɾ������ 
				for(int i=1;i<=p;i++) v.erase(it+i);//һ��һ����̬ɾ��������Ҫ�ҹ���										
			} 
			else {
				int p=v.size()/3;
				for(int i=2;i<=2*p;i+=2) v.erase(it+i);
			}
			t++;
		}		
		for(it=v.begin();it!=v.end()-1;it++) //����ֻ����������һ�� 
			cout<<*it<<' ';
		cout<<*it;
		cout<<endl;
		v.clear();
	}
}

