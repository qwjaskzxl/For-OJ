#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005;
struct node {
	int w;
	int r;//���˵�rank��������+1����Ϊÿ��һ���˽���
} mo[N]; //mo[i]��ʾ��i������

int np,ng;//��������ÿ���������
int main() {
	cin>>np>>ng;
	for(int i=0; i<np; i++)
		cin>>mo[i].w;
	queue<int>q;
	for(int i=0,m; i<np; i++) {
		cin>>m;
		q.push(m);
	}

	int t=np;//ÿ�ֵ���������Ϊÿ�ζ���ֱ����q������ţ���t����ס���ֵ���
	while(q.size()!=1) {
		int gn;//���ֵ�����
		if(t%ng==0) gn=t/ng;
		else gn=t/ng+1;
		for(int i=0; i<gn; i++) {
			int k=q.front();
			for(int j=0; j<ng; j++) {
				if(i*ng+j>=t) break;//�������������ˣ�����
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
