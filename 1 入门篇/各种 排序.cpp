#include<bits/stdc++.h>
using namespace std;

int a[100];
void select_sort(int *a, int n) //��дint a[] 
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
				for(int k=j;k<i;k++) //����д��������ѭ�������� 
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
		while(j>1&&t<a[j-1]) //��������������ж�������һ��������һ���ȴ�С�� ����ֻ��Ҫһ��ѭ���� 
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
