#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
using namespace std;
const int N=1005;
vector<int>e[N];
int inD[N];
queue<int>q;
map<string,int>mp;//name->id
vector<string>ans;

int main() { //8:52->9:39:37min
	int m;//关系数
	while(scanf("%d", &m)!=EOF, m!=0) {
		int n=0;//人数
		memset(inD,0,sizeof(inD));
		mp.clear();
		for(int i=0; i<N; i++) e[i].clear();
		while(m--) {
			string a,b;
			a.resize(20);//是字符，不是字节 
			b.resize(20);
			scanf("%s%s", &a[0],&b[0]);
			if(mp.count(a)==0)
				mp[a]=n++;
			if(mp.count(b)==0)
				mp[b]=n++;
			e[mp[a]].push_back(mp[b]);
			inD[mp[b]]++;
		}//end input

		while(!q.empty()) q.pop();
		ans.clear();
		int ok=1;//用来判断：不会有2个冠军
		for(int i=0,c=0; i<n; i++) {
			if(inD[i]==0) {
				q.push(i);
				c++;
			}
			if(c>1) {
				printf("No\n");
				ok=0;
				break;
			}
		}
		if(!ok) continue;
		int cnt=0;
		while(!q.empty()) {
			int p=q.front();
			cnt++;
			q.pop();
			for(int i=0; i<e[p].size(); i++) {
				if(--inD[e[p][i]]==0)
					q.push(e[p][i]);
			}
//			cout<<p<<' ';
		}
		printf("%s\n", cnt==n?"Yes":"No");
	}
	return 0;
}
