#include<iostream>
#include<stack>
using namespace std;
stack<int>s;//������������λ��
int main()
{
	string a,b;
	while(cin>>a)
	{
		b=a;//����Ϊ������һ��������ȳ��Ĵ�
		for(int i=0; i<a.length(); i++)
		{
			b[i]=' ';//��ʼ��
			if(a[i]=='(')
				s.push(i);
			if(a[i]==')')
			{
				if(s.empty())//��Ϊ����˵��ƥ��ʧ�ܣ�����ջ�Ļ���������ƥ����һ�� 
					b[i]='?';
				else s.pop();//��Ϊ����������ų�ջ 
			}
		}
		while(!s.empty())
		{
			b[s.top()]='$';
			s.pop();//pop��û�з���ֵ��������topȡֵ 
		}
		cout<<a<<endl<<b<<endl;
	}
	return 0;
}
