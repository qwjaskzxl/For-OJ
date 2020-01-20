#include<bits/stdc++.h>
using namespace std;

int a[100];
void select_sort(int *a, int n) //或写int a[] 
{
	for(int i=0;i<n;i++)
	{
		int mi=a[i],t=i;
		for(int j=i;j<n;j++)
		{
			if(a[j]<mi)
			{
				mi=a[j]; 
				t=j;
			}
		}
		int tmp=a[i];
		a[i]=a[t];
		a[t]=tmp;
	}
}

void insert_sort(int *a, int n)
{
	for(int i=1;i<n;i++)
	{
		int t=a[i];
		for(int j=0;j<i;j++)
		{
			if(t<a[j])
			{
				for(int k=j;k<i;k++) //楞是写出了三重循环。。。 
					a[k]=a[k-1];
				a[j]=a[i];
				break;
			}			
		}
	}
}
void insert_sort_better(int *a, int n)
{
	for(int i=1;i<n;i++)
	{
		int t=a[i],j=i;
		while(j>1&&t<a[j-1]) //巧妙的利用两个判断条件（一个计数，一个比大小） 化到只需要一个循环， 
		{
			a[j]=a[j-1];
			j--;
		}
	}
}

int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
//	select_sort(a,n);
//	insert_sort(a,n);
	insert_sort_better(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
}
