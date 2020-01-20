//DFS
#include<bits/stdc++.h>
using namespace std;
int sum=0,cnt=0;
void DFS(int step)
{
	if(sum>13||step>13) return ;
	if(sum==13&&step==13) //一遍都搜到底13，并且拿够了牌13 
	{
		cnt++;
		return ;
	}
	for(int j=0;j<=4;j++) //每张牌不拿或者拿多少 
	{
		sum+=j;
		DFS(step+1);
		sum-=j;
	}
}
int main()
{
	DFS(0);//从0开始 
	cout<<cnt;
}


//暴力法 
#include<stdio.h>
using namespace std;
int main()
{
    int sum=0;
    for(int i1=0;i1<=4;i1++)
    for(int i2=0;i2<=4;i2++)
    for(int i3=0;i3<=4;i3++)
    for(int i4=0;i4<=4;i4++)
    for(int i5=0;i5<=4;i5++)
    for(int i6=0;i6<=4;i6++)
    for(int i7=0;i7<=4;i7++)
    for(int i8=0;i8<=4;i8++)
    for(int i9=0;i9<=4;i9++)
    for(int i10=0;i10<=4;i10++)
    for(int i11=0;i11<=4;i11++)
    for(int i12=0;i12<=4;i12++)
    for(int i13=0;i13<=4;i13++)
    {
        if(i1+i2+i3+i4+i5+i6+i7+i8+i9+i10+i11+i12+i13==13)
        {
            sum++;
        }
    }
    printf("%d\n",sum);
}
