/*
��Ŀ������
һ���ܳ�������������N (2 <= N <= 100,000)�����䣬
��ЩС�������α��Ϊx1,��,xN (0 <= xi <= 1,000,000,000).
���ǣ�John��C (2 <= C <= N)ͷţ�ǲ���ϲ�����ֲ��֣�
���Ҽ�ͷţ����һ�������
���Ǿ�Ҫ����������Ϊ�˲���ţ�����˺���
John�����Լ���ţ������䣬ʹ������ͷţ֮�����С���뾡���ܵĴ�
��ô�����������С������ʲô�أ�

���룺
�ж���������ݣ���EOF������ ��һ�У��ո�ָ�����������N��C �ڶ��С�����N+1�У��ֱ�ָ����xi��λ��

�����
ÿ������������һ�����������������������Сֵ��ע�⻻�С�

��������
5 3
1
2
8
4
9
�������
3
*/

//ֱ��ѡ��������ϣ�Ȼ�����򡣡���ѡ����Min 
#include<iostream>
#include<string.h>
#include<set>
using namespace std;
set<int>SE;
set<int>::iterator it;
int n,m;
unsigned long long Map[100005],vst[100005];
unsigned long long a[100005],Max=0;
void C(int x)
{
	if(x==m)//ע���0��ʼ���ǵ����� 
	{		
		SE.clear();
		for(int i=0;i<m;i++)
			SE.insert(Map[a[i]]);						
		int Min=99999;
		for(it=SE.begin(); ++it!=SE.end(); )//�������ûд++�� 
			{
				it--;
				int a1=*it, a2=*++it;
				if(Min>a2-a1) Min=a2-a1;				
			}
		if(Min>Max) Max=Min;
		return ;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!vst[i]) 
		{		
			a[x]=i;
			if(a[x]<a[x-1]) continue;
			vst[i]=1;
			C(x+1);
			vst[i]=0; 
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>Map[i];
	memset(vst,0,sizeof(vst));
	C(0);
	cout<<Max;
}

//POJ ��Ҫ�� ����ö�ٲ��ܲ�TLE 
#include<stdio.h>    
#include<stdlib.h>  
#include<algorithm>   
using namespace std;   
int a[100005],n,c;    
int judge(int mid)    
{    
    int i,count=1,t=a[0]; //count��ָ���˼�ͷţ����1��ʼ��t������ʾ��ǰ�ķ����  
    for(i=1;i<n;i++)  
    {  
        if(a[i]-t>=mid)//�ж���������֮��ľ���   
        {    
            count++;  
            t=a[i];//�޸�t��ֵ�����޸ĵ�ǰ����ţ�����ԭ��t=1,a[2]=4,��a[2]-t>=mid���ϣ���ôt=4,Ȼ����a[3]����a[4]��t֮��ľ��롣    
            if(count>=c)//���Է���Cͷţ    
                return 1;
        }  
    }    
    return 0;  
}    
int binary()//��������������������С��������ֵ    
{    
    int low=0,high=a[n-1]-a[0],mid;    
    while(low<=high)    
    {    
        mid=(low+high)/2;//mid��Ϊ��С���������󷿼��֮��ľ���    
        if(judge(mid))   
            low=mid+1; //�������>=mid�����Լ���������̽   
        else    
            high=mid-1;//�������<mid�����Ա����С����̽    
    }    
    return low-1; //������֮ǰ����+1�����Դ�ʱ-1   
}     
int main()    
{    
    while(~scanf("%d%d",&n,&c))    
    {    
        int i;    
        for(i=0;i<n;i++)    
            scanf("%d",&a[i]);    
        sort(a,a+n);
        printf("%d\n",binary());    
    }    
    return 0;    
}   
