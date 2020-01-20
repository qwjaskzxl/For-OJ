#include<iostream>
using namespace std;
int n,i,j,k;//n保证是奇数
char a,b;//外框，次外框（注意，因为是奇数，外框和中心是一样的图案）
char out[82][82];//正是因为这样的不方便顺序输出，所以利用数组
int nxt[4][2]= {0,1,1,0,0,-1,-1,0}; //右下左上的顺序

int main()
{
	while(cin>>n)
	{
		if(!n) break;
		cin>>a>>b;
		if(n==1)//特判1，忘记考虑了
		{
			cout<<a<<endl;	
			continue;
		} 
		//还是要利用规律。王道用的是内到外，我是想一圈圈画
		for(i=1; i<=(n+1)/2; i++) //画(n+1)/2圈
		{
			int x=i,y=i;//从(i,i)开始画
			char c=i%2==1?a:b;//是奇数就画外框
			int nx=x,ny=y;
			for(j=0; j<4; j++) //右下左上方向来转圈画
			{
				for(k=0; k<n-2*i+1; k++)
				{
					out[nx][ny]=c;
					nx+=nxt[j][0];
					ny+=nxt[j][1];
				}

			}
		}
		//中心没画上，补上：
		out[(n+1)/2][(n+1)/2]=(n+1)/2 %2==1?a:b;//是奇数就是外框 
		out[1][1]=out[1][n]=out[n][1]=out[n][n]=' ';//抹掉4个
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
				cout<<out[i][j];
			cout<<endl;
		}
	}
	return 0;
}

