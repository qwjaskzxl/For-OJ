//#include<bits/stdc++.h>
//#include<vector>
//using namespace std;
//const int Mod=100000007;
//
//int main()
//{
//	
//}
#include<bits/stdc++.h>
using namespace std;

int n,a[10],vst[10];
int DFS(int step)
{
	if(step==n+1)
	{
		for(int i=1;i<=n;i++) 
			cout<<a[i];
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])//û���� 
		{
			vst[i]=1;//�����д�������ԣ�����Ȥ 
			a[step]=i;//����i���� 
			DFS(step+1); 
			vst[i]=0;//�����ó��� 
		}
	}
	return 0;//������ʵ�Ǳ�ʾ ��������������main���return 0 
}

int main()
{
	memset(vst,0,sizeof(vst));
//	vst[3][3]=1;
	DFS(1);
	cout<<n/4; //��Ϊ���ĶԳ� 
}
