/*
2
#include<iostream> 
#include<algorithm> 
#include<set>
using namespace std;
set<int>SE; //�Զ��ɴ�С����� 
set<int>::iterator it;
int main()
{
	int n;cin>>n;
	int a;
	while(n--){		
		cin>>a;
		SE.insert(a);
	}
	
	for(it=SE.begin();it!=SE.end();it++) cout<<*it<<' ';
	
}

4
#include<iostream> 
#include<algorithm> 
#include<set>
using namespace std;
set<string>SE; 
set<string>::iterator it;
int main()
{
	int n;cin>>n;
	string a,b;
	cin>>a;
	while(n--){
		cin>>b;
		SE.insert(b);
	}
	if(SE.erase(a)) //����ɹ� 
		for(it=SE.begin();it!=SE.end();it++) cout<<*it<<' ';
	else cout<<"song";		
}
*/

#include<iostream> 
#include<algorithm> 
#include<set>
using namespace std;
set<int>SE; 
set<int>::iterator it;
int main()
{
	int A;cin>>A;
//	getchar();  //��ֹA����Ŀո񣬵���ʵ�����cin int���Ժ��Ե��ո��Ӱ�� 
	int a,m;
	for(int i=0;i<A;i++){
		cin>>a;
		SE.insert(a);
		while(getchar()!='\n') //�Ե��ո�
		{
			cin>>a;
			if(SE.count(a)) m=a;
			SE.insert(a);
		}
	}
	for(it=SE.begin(); *++it-*--it==1; it++);
	cout<<*it+1<<' '<<m;
	return 0;
}
