#include<iostream>
using namespace std;
int n,i,j,k;//n��֤������
char a,b;//��򣬴����ע�⣬��Ϊ������������������һ����ͼ����
char out[82][82];//������Ϊ�����Ĳ�����˳�������������������
int nxt[4][2]= {0,1,1,0,0,-1,-1,0}; //�������ϵ�˳��

int main()
{
	while(cin>>n)
	{
		if(!n) break;
		cin>>a>>b;
		if(n==1)//����1�����ǿ�����
		{
			cout<<a<<endl;	
			continue;
		} 
		//����Ҫ���ù��ɡ������õ����ڵ��⣬������һȦȦ��
		for(i=1; i<=(n+1)/2; i++) //��(n+1)/2Ȧ
		{
			int x=i,y=i;//��(i,i)��ʼ��
			char c=i%2==1?a:b;//�������ͻ����
			int nx=x,ny=y;
			for(j=0; j<4; j++) //�������Ϸ�����תȦ��
			{
				for(k=0; k<n-2*i+1; k++)
				{
					out[nx][ny]=c;
					nx+=nxt[j][0];
					ny+=nxt[j][1];
				}

			}
		}
		//����û���ϣ����ϣ�
		out[(n+1)/2][(n+1)/2]=(n+1)/2 %2==1?a:b;//������������� 
		out[1][1]=out[1][n]=out[n][1]=out[n][n]=' ';//Ĩ��4��
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
				cout<<out[i][j];
			cout<<endl;
		}
	}
	return 0;
}

