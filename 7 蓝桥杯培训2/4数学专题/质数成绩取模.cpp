#include <bits/stdc++.h> 
using namespace std;
int main()
{	
	int n,N=0;
	cin>>n; 	
	unsigned long long sum=1;	
		for(int zs=2;N<n;zs++) //���� 
		{			
			int t=1;
			for(int j=2;j<=sqrt(zs);j++) //�ж� 
			{
				if(zs%j==0){
					t=0;
					break;
				}
			}
			if(t){				
				sum=(sum%50000)*(zs%50000)%50000;//�������ȼ���һ���� 
				N++;
			} 
		}
	cout<<sum;	
}

