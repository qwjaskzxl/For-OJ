//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int n;cin>>n;
//	int a[50];
//	for(int i=0;i<n;i++) cin>>a[i];
//	int sum=1;
//	if(a[0]<0)
//	{
//		for(int i=1;i<n;i++) 
//		{
//			if(a[i]>0&&a[i]<-a[0]) sum++;
//		}
//		if(sum==1){cout<<sum;return 0;}
//		else
//		{
//			for(int i=1;i<n;i++) 
//			{
//				if(a[i]<0&&-a[i]>-a[0]) sum++;
//			}
//		}
//		cout<<sum;
//	}
//	else
//	{
//		for(int i=1;i<n;i++) 
//		{
//			if(a[i]<0&&-a[i]>a[0]) sum++;
//		}
//		if(sum==1){cout<<sum;return 0;}
//		else
//		{
//			for(int i=1;i<n;i++) 
//			{
//				if(a[i]>0&&a[i]<a[0]) sum++;
//			}
//		}
//		cout<<sum;
//	}
//}

//更简单的，直接用abs 
#include<iostream>  
#include<cmath>  
using namespace std;  
int main()  
{  
    int a[100];  
    int n;  
    while(cin>>n)  
    {  
        int i,j,k;  
        int l=0,r=0;  
        for(i=0;i<n;i++)  
        {  
            cin>>a[i];  
        }  
        for(i=1;i<n;i++)  
        {  
            if(fabs(a[i])>fabs(a[0])&&a[i]<0)  
                l++;  
            if(fabs(a[i])<fabs(a[0])&&a[i]>0)  
                r++;  
        }  
        if(a[0]<0&&r==0||a[0]>0&&l==0)  
            cout<<"1"<<endl;  
        else  
        cout<<l+r+1<<endl;  
  
    }  
}  

