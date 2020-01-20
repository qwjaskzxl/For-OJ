#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=102;
struct node {
	int a,b,c;//��ʵ������������������
	int t;
} s,v;
queue<node>q;
int vis[N][N][N];
int V,x,y;//���������������

void A2B(int &a, int va, int &b, int vb) { //ԭʼ����������������������õ�A->B����¿������
	if(a>vb-b) { //a�Ŀ�����vb��װ����
		a-=vb-b;//˳���ܵߵ�����
		b=vb;
	} 
	else {
		b+=a;
		a=0;
	}
}
int check(int a,int b,int c) {
	int k=V/2;
	if(a==k&&b==k || b==k&&c==k || a==k&&c==k)
		return 1;
	return 0;
}
int BFS() {//���������·����ζ��BFS�ܺ���
	s.a=V;
	s.b=s.c=s.t=0;
	q.push(s);
	vis[V][0][0]=1;
	while(!q.empty()) {
		s=q.front();
		q.pop();
		int a=s.a;
		int b=s.b;
		int c=s.c;
//		cout<<a<<' '<<b<<' '<<c<<'\n';
		A2B(a,V,b,x);//a->b
		if(!vis[a][b][c]) {
			if(check(a,b,c))
				return s.t+1;
			vis[a][b][c]=1;
			v.a=a;
			v.b=b;
			v.c=c;
			v.t=s.t+1;
			q.push(v);
		}

		a=s.a;
		b=s.b;
		c=s.c;
		A2B(b,x,a,V);//b->a
		if(!vis[a][b][c]) {
			if(check(a,b,c))
				return s.t+1;
			vis[a][b][c]=1;
			v.a=a;
			v.b=b;
			v.c=c;
			v.t=s.t+1;
			q.push(v);
		}

		a=s.a;
		b=s.b;
		c=s.c;
		A2B(a,V,c,y);//a->c
		if(!vis[a][b][c]) {
			if(check(a,b,c))
				return s.t+1;
			vis[a][b][c]=1;
			v.a=a;
			v.b=b;
			v.c=c;
			v.t=s.t+1;
			q.push(v);
		}

		a=s.a;
		b=s.b;
		c=s.c;
		A2B(c,y,a,V);//c->a
		if(!vis[a][b][c]) {
			if(check(a,b,c))
				return s.t+1;
			vis[a][b][c]=1;
			v.a=a;
			v.b=b;
			v.c=c;
			v.t=s.t+1;
			q.push(v);
		}

		a=s.a;
		b=s.b;
		c=s.c;
		A2B(b,x,c,y);//b->c
		if(!vis[a][b][c]) {
			if(check(a,b,c))
				return s.t+1;
			vis[a][b][c]=1;
			v.a=a;
			v.b=b;
			v.c=c;
			v.t=s.t+1;
			q.push(v);
		}

		a=s.a;
		b=s.b;
		c=s.c;
		A2B(c,y,b,x);//c->b
		if(!vis[a][b][c]) {
			if(check(a,b,c))
				return s.t+1;
			vis[a][b][c]=1;
			v.a=a;
			v.b=b;
			v.c=c;
			v.t=s.t+1;
			q.push(v);
		}
	}
	return 0;
}
int main() {
	while(scanf("%d%d%d", &V,&x,&y)!=EOF) {
		if(!V&&!x&&!y) break;
		if(V&1) printf("NO\n");//prune,��������ƽ��
		else {
			memset(vis,0,sizeof(vis));
			while(!q.empty()) q.pop();
			int ans=BFS();
			if(ans) printf("%d\n", ans);
			else printf("NO\n");
		}
	}
	return 0;
}
