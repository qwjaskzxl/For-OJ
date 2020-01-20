#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int N=100005;
struct node {
	int prior,next;
	int data;
} L[N];

int main() {
	int st,n,k;
	cin>>st>>n>>k;
	L[st].prior=-1;
	while(n--) {
		int a,b,c;
		cin>>a>>c>>b;
		L[a].data=c;
		L[a].next=b;
		if(b!=-1) L[b].prior=a;
	}
	int p=st;

	for(int i=1; p!=-1; i++) {
		if(i%k!=0) {
			int p2=L[p].next;
			L[p].next=L[p].prior;
			p=p2;
		} 
		else {
			

		}
	}
	L[st].
	L[p].next=st;
	return 0;
}
