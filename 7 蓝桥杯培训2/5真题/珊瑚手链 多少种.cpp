/*
��3�ź�ɺ����4�Ű�ɺ����5�Ż���解������Ǵ���һȦ��Ϊ������ 
�������������������ת����ת��һ�������ж��ٲ�ͬ�������ʽ�أ�
*/

//�ɷ�ת��ʵ���ǣ���reverse���������� 

/*
������˼·�������ܰ��� 

����⣬��Ҫ����stl�е�
string.find(str),
next_permutation(str.begin(),str.end()),
reverse(str.begin,str.end())��
��һ��vector�д����Ѿ����ֹ������У�
ÿһ����������vector�в����Ƿ��Ѵ��ڸ����У�
�������ڣ���res++��
����str+str(������ת��)��reverse(str.begin(),str.end()) (�����ⷭת) 
ѹ��vector��
�����Ļ����Ƚϻ�ʱ�䣬���ǿ��Խ��ܡ�
*/

#include<bits/stdc++.h>
using namespace std;
vector<string> vec;
int main()
{
    string str="AAABBBBCCCCC";
    int res=0;
    do
    {
        int flag=1;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].find(str)!=string::npos) //���� a�Ƿ�����Ӵ�b��д�� 
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            res++;
            string tmp=str+str;//��Ϊ�ǻ��������������൱���������� 
            vec.push_back(tmp);
            reverse(tmp.begin(),tmp.end());
            vec.push_back(tmp);
        }
    }while(next_permutation(str.begin(),str.end()));
    cout<<res<<endl;
    return 0;
}

/*
ʹ������ѧ��������
12��/��3��*4��*5��*12��=2310�֣����ǲ����ǿ��Է�ת�Ĵ𰸡�
�����Ƿ�ת��Ҫ�����Щ���ҶԳƵ������
��1��A��1��C���߶���5����ʣ��2��A��4��B��4��C�����߶Գƣ�
����ABBCC���У���5��/��2*2��=30�֡�
�������ս����30+��2310-30��/2=1170��
*/
