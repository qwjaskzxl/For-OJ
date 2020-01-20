#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=205;
const int INF=0x3fffffff;
int mapp[N][N];//x->y的cost
int n,m;//路口数，道路数
void Floyd() {
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(mapp[i][k]!=INF && mapp[k][j]!=INF &&
				        mapp[i][j]>mapp[i][k]+mapp[k][j])
					mapp[i][j]=mapp[i][k]+mapp[k][j];//否则都保持原样
			}
}
int main() {
	while(scanf("%d%d", &n,&m)!=EOF) {
		if(!n&&!m) break;
		fill(mapp[0],mapp[0]+N*N,INF);//除了 到自己，都init为INF
		for(int i=1; i<=n; i++) mapp[i][i]=0;
		while(m--) {
			int a,b,c;
			scanf("%d%d%d", &a,&b,&c);
			mapp[a][b]=mapp[b][a]=c;
		}
		Floyd();
		printf("%d\n", mapp[1][n]);
	}
	return 0;
}
