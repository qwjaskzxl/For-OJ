#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;cin>>n;
	int i,j,k,l;
	i=j=k=l=0;
	for(i=0; ;i++)
	{
		if(i>=sqrt(n)) break;
		for(j=0; ;j++)
		{
			if(j>=sqrt(n)) break;
			for(k=0; ;k++)
			{	
				if(k>=sqrt(n)) break;
				l=sqrt(n-i*i-j*j-k*k);
				if(l==int(l))	//很关键 
//				for(l=0; ;l++)
				{
					if(i*i+j*j+k*k+l*l==n) 
					{
						cout<<i<<' '<<j<<' '<<k<<' '<<l;
						return 0;
					}		
					if(l>=sqrt(n)) break;				
				}
			}
		}	
	}	
}

//#include <stdio.h>  
//#include <math.h>  
//  
//int mpt[5000010] ={0};  //mpt[i] = 1表示i 能够用两个完全平方数相加而得。  
//int n;  
//  
//void init()  
//{  
//    for(int i = 0 ; i*i <= n ; i ++)  
//        for(int j = 0 ; j*j <=n ; j ++)  
//            if(i*i+j*j <= n) mpt[i*i+j*j] = 1;  
//}  
//  
//int main()  
//{  
//    int flag = false;  
//    scanf("%d",&n);  
//    init();  
//    for(int i = 0 ; i * i <= n ; i ++)  
//    {  
//        for(int j = 0 ; j * j <= n ; j ++){  
//            if(mpt[n - i*i - j*j] == 0)  
//                continue;   //如果剩下的差用两个完全平方数不能组合出来就不继续  
//  
//            for(int k = 0 ; k * k <= n ; k ++)  
//            {  
//                int temp = n - i*i - j*j - k*k;  
//                double l = sqrt((double) temp);  
//                if(l == (int)l )  
//                {  
//                    printf("%d %d %d %d\n",i,j,k,(int)l);  
//                    flag = true;  
//                    break;  
//                }  
//            }  
//            if(flag)break;  
//        }  
//        if(flag)break;  
//    }  
//    return 0;  
//}  
