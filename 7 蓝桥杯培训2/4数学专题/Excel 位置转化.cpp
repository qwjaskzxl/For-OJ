/*��Ŀ������
Excel����õİ칫�����ÿ����Ԫ����Ψһ�ĵ�ַ��ʾ�����磺��12�е�4�б�ʾΪ����D12������5�е�255�б�ʾΪ��IU5���� ��ʵ�ϣ�Excel�ṩ�����ֵ�ַ��ʾ����������һ�ֱ�ʾ������RC��ʽ��ַ�� ��12�е�4�б�ʾΪ����R12C4������5�е�255�б�ʾΪ��R5C255���� ��������ǣ���д����ʵ�ִ�RC��ַ��ʽ�������ַ��ʽ��ת����

���룺
�û�������һ������n��n<100������ʾ��������n���������ݡ�

���������n��������RC��ʽ��Excel��Ԫ���ַ��ʾ����
�����
�������n�����ݣ�ÿ����ת����ĳ����ַ��ʾ����

��������
2
R12C4
R5C255
�������
D12
IU5
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
char Z[28]={"0ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
vector<char>v,CC;
int main()
{
	int n;cin>>n;
	int R,C;
	while(n--)
	{
		CC.clear();
		getchar();//����Ҫ...�Ե������з��� 	
		scanf("R%dC%d",&R,&C);	//Ϊʲôû�뵽�أ�			
		while(C%26)
		{		
			CC.push_back(Z[C%26]);
			C/=26;	
		}
//		reverse(CC.begin(),CC.end());//��ת
		for(int i=CC.size()-1;i>=0;i--)
			cout<<CC[i];
		cout<<R<<endl;
	}
}
