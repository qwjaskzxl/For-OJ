/*
2
#include<iostream> 
#include<algorithm> 
#include<set>
using namespace std;
set<int>SE; //自动由大到小排序的 
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
	if(SE.erase(a)) //清除成功 
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
//	getchar();  //防止A后面的空格，但其实后面的cin int可以忽略掉空格的影响 
	int a,m;
	for(int i=0;i<A;i++){
		cin>>a;
		SE.insert(a);
		while(getchar()!='\n') //吃掉空格
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
