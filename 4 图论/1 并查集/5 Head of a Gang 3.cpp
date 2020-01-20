#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005;
int tree[N];//用树表示集合，每个元素的值是它的父节点编号
map<string,int>mp;
int tim[N];
string name[N];//到名字的映射
int sum[N];//集体的时间
struct cluster { //最后得到集体
	int root;
	vector<int>m;
} clus[N];
struct Ans {
	int sum=0;
	string name;
} ans[N];
int cmp(Ans a, Ans b) {
	return a.name<b.name;
}
int find_root(int x) {
	if(tree[x]==-1) return x;
	else {
		int root=find_root(tree[x]);//递归找根
		tree[x]=root;//路径压缩
		return root;
	}
}

int main() { //16:44->18...
	int n,k;//电话数，阈值
	scanf("%d%d", &n,&k);
	memset(tree,-1,sizeof(tree));
	memset(tim,0,sizeof(tim));
	memset(sum,0,sizeof(sum));
	string a,b;//名字
	int t;//时间
	int num=0;//人数
	while(n--) {
		cin>>a>>b>>t;
		if(mp.count(a)==0) { //转化为数字
			mp[a]=num++;
			name[num-1]=a;
		}
		if(mp.count(b)==0) {
			mp[b]=num++;
			name[num-1]=b;
		}
		tim[mp[a]]+=t;
		tim[mp[b]]+=t;
		int ma=find_root(mp[a]);//不能改mp[a]!
		int mb=find_root(mp[b]);
		if(ma!=mb) {
			tree[ma]=mb;//合并
			sum[mb]+=sum[ma]+t;//一个集体的总时间
		} else sum[ma]+=t; //sum[mb]也可以
	}
//		for(int i=0;i<num;i++)
//			cout<<tim[i]<<' '<<sum[i]<<'\n';

	int c_num=0;//集体数
	for(int i=0; i<num; i++) {
		if(tree[i]==-1 && sum[i]>k)
			clus[c_num++].root=i;
	}
	for(int i=0; i<num; i++) {
		if(tree[i]!=-1) {
			int f=find_root(i);
			for(int j=0; j<c_num; j++) {
				if(f==clus[j].root) {
					clus[j].m.push_back(i);//把每个clu都存一起
				}
			}
		}
	}

	int ok_num=0;//满足条件的集体数
	for(int i=0; i<c_num; i++) {
		if(clus[i].m.size()>1) {//有2个人以上
			int id=clus[i].root;
			int maxx=tim[clus[i].root];
			for(int j=0; j<clus[i].m.size(); j++) {
//					cout<<clus[i].m[j]<<' ';
				if(tim[clus[i].m[j]] > maxx) {
					id=clus[i].m[j];
					maxx=tim[clus[i].m[j]];
				}
			}
//				printf("\n%s %d\n", name[id].c_str(),clus[i].m.size()+1);
			ans[ok_num].name=name[id];
			ans[ok_num++].sum=clus[i].m.size()+1;
		}
	}
	printf("%d\n", ok_num);
	sort(ans,ans+ok_num,cmp);
	for(int i=0; i<ok_num; i++)
		printf("%s %d\n", ans[i].name.c_str(),ans[i].sum);
	return 0;
}

