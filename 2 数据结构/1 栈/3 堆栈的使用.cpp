#include<iostream>
#include<stack>
using namespace std;

stack<int>s;

int main()
{
	int n;
	while(cin>>n, n!=0)
	{
		while(!s.empty()) s.pop();//别放里面init了呀。。。 
		while(n--)
		{
			char c;
			int a;
			cin>>c;
			if(c=='P')
			{
				cin>>a;
				s.push(a);
			}
			if(c=='O' && !s.empty()) 
				s.pop();
			if(c=='A')
			{
				if(!s.empty())
					cout<<s.top()<<'\n';
				else cout<<"E\n";
			}
		}
		cout<<endl;
	}
	return 0;
}
