#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string a;
int main() {
	int n;
	a.resize(10);
	while(scanf("%s",&a[0])!=EOF) {//cin也AC，不要加!cin.eof()反而错了。。 
		n=strlen(a.c_str());
		do {
			printf("%s\n",a.c_str());
		} while(next_permutation(a.begin(),a.begin()+n));//不能到a.end() 但是用cin的话是可以的
		printf("\n");//或者用puts("") 会自动加上换行
	}
	return 0;
}

//下面这个没调好，反正原理是需要swap和reverse 
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 1e5+5;
// 
//void Reverse(char a[],int l,int r)
//{
//	while(l<r){
//		swap(a[l],a[r]);
//		l++;r--;
//	}
//}
// 
//bool Next_permutatin(char a[],int l,int r)
//{
//	int i=r-1;
//	while(i!=0&&a[i]>=a[i+1]) i--;
//	if(i==-1) return false;
//	int j=r;
//	while(a[j]<=a[i]) j--;
//	swap(a[i],a[j]);
//	Reverse(a,i+1,r);
//	return true;
//}
//int main()
//{
//	char a[N];
////	a[1]=1;a[2]=1;a[3]=2;a[4]=4;
//	scanf("%s", a);
//	do
//	{
//		printf("%s\n", a);
//	}while(Next_permutatin(a,0,strlen(a)-1));
// 
//}
