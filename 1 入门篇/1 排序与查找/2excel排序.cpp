#include<iostream>
#include<algorithm>
using namespace std;
struct S
{
	string num;
	string name;
	int g;
} s[100005];
int cmp1(S a,S b)
{
	return a.num<b.num;
}
int cmp2(S a,S b)
{
	if(a.name==b.name)
		return a.num<b.num;
	return a.name<b.name;
}
int cmp3(S a,S b)
{
	if(a.g==b.g)
		return a.num<b.num;
	return a.g<b.g;
}

int main()
{
	int n,i,t=1;//����������ʽ
	while(cin>>n>>i)
	{
		if(!n) break;
		for(int j=0; j<n; j++)
		{
			s[j].num.resize(10);//����ҪԤ�ȷ���ռ䣬��Ȼ��ȫ���� 
			s[j].name.resize(10);
			scanf("%s%s%d" ,&s[j].num[0],&s[j].name[0],&s[j].g);
//			cin>>s[j].num>>s[j].name>>s[j].g;
		}

		switch(i)
		{
			case 1:
				sort(s,s+n,cmp1);
				break;
			case 2:
				sort(s,s+n,cmp2);
				break;
			case 3:
				sort(s,s+n,cmp3);
		}
		printf("Case %d:\n",t++);//����дͦ���� 
		for(int j=0; j<n; j++)
			printf("%s %s %d\n" ,s[j].num.c_str(),s[j].name.c_str(),s[j].g);
//			cout<<s[j].num<<' '<<s[j].name<<' '<<s[j].g<<endl; 
	}
	return 0;
}

