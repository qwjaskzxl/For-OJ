#include<iostream>
using namespace std;
/*
1.���ո���ַ����Ķ�ȡ��������������׳�bug
2.�����ִ�Сд�Ϳ����ȶ�תΪΪСд������tolower()�������Ե����ַ�����
  ������ (abs(a - b) == 32 || a == b)�ж������ַ����
3.����ֱ�Ӱ�char���鸳ֵ��string
4.string��erase������ Ҫɾ������ʼλ��+��ɾ���Ķ�
*/
char str[100000];
int main()
{
	string x;
	cin>>x;
	getchar();//�Ե���һ������Ǹ����з�
	for(int i=0; i<x.size(); i++) //��Ϊ�����ִ�Сд������ȫ��ת��ΪСд
		x[i]=tolower(x[i]);
		
	while(gets(str))
	{
		string s=str,s_ori=str;//��Ҫ����ԭ�����Լ�����ƥ���Сд��
		for(int i=0; i<s.size(); i++)
			s[i]=tolower(s[i]);
		while(s.find(x)!=string::npos)
		{
			int t=s.find(x);
			s.erase(t,x.size());
			s_ori.erase(t,x.size());
		}

		for(int i=0; i<s_ori.size(); i++)
			if(s_ori[i]!=' ')
				cout<<s_ori[i];
		cout<<endl;
	}
	return 0;
}
