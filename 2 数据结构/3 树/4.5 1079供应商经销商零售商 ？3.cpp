#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
const int N=100005;

vector<int>tree[N];//��Χ����0~n-1
int n,maxDep=0,num=0;//��Ȳ���initΪ-1����Ϊ��0����� 
double p,r;
void DFS(int T,int dep) { //�����BFS������ֱ��
	if(tree[T].size()==0) { //��Ҷ��Node��
		if(dep>maxDep) {
			maxDep=dep;
			num=1;
		} else if(dep==maxDep) num++;
		return ;
	}
	for(int i=0; i<tree[T].size(); i++) {
		DFS(tree[T][i],dep+1);
	}
}
int layer[N]= {0};
void BFS(int T) {
	queue<int>q;
	q.push(T);
	while(!q.empty()) {
		int t=q.front();
		q.pop();
		for(int i=0; i<tree[t].size(); i++) {
			layer[tree[t][i]]=layer[t]+1;
			maxDep=layer[tree[t][0]];
			q.push(tree[t][i]);
		}
	}
}
int main() {
	cin>>n>>p>>r;
	int root;
	for(int i=0,a; i<n; i++) {
		cin>>a;
		
	}
//	DFS(root,0);//ֻҪ֪�������������ˣ����powһ��
	BFS(root);
	for(int i=0; i<n; i++) {
		if(layer[i]==maxDep) num++;
	}
	printf("%.2lf %d", p*pow(1+r/100,maxDep),num);
	return 0;
}
