#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],vst[100]; 
long long cnt=0;
void DFS(int step)
{
	if(step==m+1)//���ȫ���У����Ըģ�Ҳ���ǿ���A43���� 
	{
//		for(int i=1;i<=m;i++)
//			cout<<a[i];
//		cout<<endl;
		cnt++;
		return ;
	}
	for(int i=1;i<=n;i++)//i���� 
	{
		if(!vst[i])//i����û����
		{
			a[step]=i;//�ŵ�step���� 
			//if(a[step]<a[step-1]) continue;//����������ã���Ϊֻ�������OK��	
			vst[i]=1;//�����д�����㼸���ݣ�10��10Ҫ50s 
			DFS(step+1);//����һ������
			vst[i]=0;//�����ó���
		}
	}
	return ;//��ʾ ��������������main���return 0����дӦ��Ҳ�� 
}
int main()
{
	cin>>n>>m;
	DFS(1);//��1��ʼ 
	cout<<cnt;
}
