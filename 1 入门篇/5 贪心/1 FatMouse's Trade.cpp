#include<iostream>
#include<algorithm>
using namespace std;
struct S
{
	double j,f;//�ջ񣬴���
} s[1005];
int cmp(S a,S b)
{
	return a.j/a.f > b.j/b.f;//����ÿ��ѡ����
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n) && (m!=-1&&n!=-1))//����ֻҪһ�� 
	{
		for(int i=0; i<n; i++)
			cin>>s[i].j>>s[i].f;
		sort(s,s+n,cmp);

		int i=0;
		double sum=0;
		while(m>0&&i<n)//�Լ�m�����ˣ���Է�û���ܻ����ˣ����������Ҫ��ֹ
		{
			if(m-s[i].f>0.001)//������Ҫ�����жϴ�С��
			{
				m-=s[i].f;
				sum+=s[i].j;
				i++;
			}
			else
			{
				sum+=m/s[i].f*s[i].j;
				m=0;
			}
		}
		printf("%.3lf\n",sum);//double��lf
	}
	return 0;
}
