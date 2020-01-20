#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005;
struct node {
	int w;
	int r;//挂了的rank就是组数+1，因为每组一个人晋级
} mo[N]; //mo[i]表示第i个老鼠

int np,ng;//总人数，每组最大人数
int main() {
	cin>>np>>ng;
	for(int i=0; i<np; i++)
		cin>>mo[i].w;
	queue<int>q;
	for(int i=0,m; i<np; i++) {
		cin>>m;
		q.push(m);
	}

	int t=np;//每轮的人数，因为每次都是直接往q里继续放，用t来卡住该轮的人
	while(q.size()!=1) {
		int gn;//本轮的组数
		if(t%ng==0) gn=t/ng;
		else gn=t/ng+1;
		for(int i=0; i<gn; i++) {
			int k=q.front();
			for(int j=0; j<ng; j++) {
				if(i*ng+j>=t) break;//超过本轮人数了，卡断
				if(mo[q.front()].w > mo[k].w) {
					k=q.front();
				}
				mo[q.front()].r=gn+1;
				q.pop();
			}
			q.push(k);
		}
		t=gn;
	}
	mo[q.front()].r=1;
	for(int i=0; i<np-1; i++)
		cout<<mo[i].r<<' ';
	cout<<mo[np-1].r;
	return 0;
}
