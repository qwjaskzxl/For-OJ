//for循环 穷举 
#include<bits/stdc++.h> 
#include<vector>
using namespace std;
vector<int>v;
int main()
{
	int a,b,n=0;
	cin>>a>>b;
	if(a>b)
	{
		int t=a;a=b;b=t;
	}
	for(int i=b;i<=a*b;i++)
	{		
		for(int j=0,k=0; ;j+=b)
		{
			k=0;
			if(j+k>i) break;
			for(;;k+=a)
			{		
				if(j+k>i) break;		
				if(j+k==i)
				{
					v.push_back(i);
					break;
				}
			}
			if(j+k==i) break;
		}
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		if(v[i]-v[i-1]>1) 
		{
			cout<<v[i]-1;
			break;
		}
	}
}

//DFS 
#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,Flag;
int a[101];
void DFS(int x,int y,int n)
{
	if(a*x+b*y>n) return ;
	if(a*x+b*y==n)
	{
		Flag=0;
		return ;
	}	
	DFS(x+1,y,n);
	DFS(x,y+1,n);	
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=a*b;i++)
	{
		Flag=1;
		DFS(0,0,i);
		cout<<i<<' '<<Flag<<endl;
		cnt+=Flag;
	}
	cout<<cnt;
}

//回溯法 穷举 
#include<iostream>
using namespace std;
int fun(int num,int i,int j)
{
    if(num < 0)
        return 0;
    else if(num == 0)
        return 1;
    else
    {
        return fun(num-i,i,j) + fun(num-j,i,j);
    }
} 
int main()
{
    int i,j;
    int count = 0;
    cin>>i>>j;
    for(int k=i;k<=i*j;k++)
    {
        if(!fun(k,i,j))
            {
                count = k;
            }
    }
    cout<<count<<endl;
}

数学法:a*b-a-b就OK了 
