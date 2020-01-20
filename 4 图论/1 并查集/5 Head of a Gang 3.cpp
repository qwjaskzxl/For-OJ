#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005;
int tree[N];//������ʾ���ϣ�ÿ��Ԫ�ص�ֵ�����ĸ��ڵ���
map<string,int>mp;
int tim[N];
string name[N];//�����ֵ�ӳ��
int sum[N];//�����ʱ��
struct cluster { //���õ�����
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
		int root=find_root(tree[x]);//�ݹ��Ҹ�
		tree[x]=root;//·��ѹ��
		return root;
	}
}

int main() { //16:44->18...
	int n,k;//�绰������ֵ
	scanf("%d%d", &n,&k);
	memset(tree,-1,sizeof(tree));
	memset(tim,0,sizeof(tim));
	memset(sum,0,sizeof(sum));
	string a,b;//����
	int t;//ʱ��
	int num=0;//����
	while(n--) {
		cin>>a>>b>>t;
		if(mp.count(a)==0) { //ת��Ϊ����
			mp[a]=num++;
			name[num-1]=a;
		}
		if(mp.count(b)==0) {
			mp[b]=num++;
			name[num-1]=b;
		}
		tim[mp[a]]+=t;
		tim[mp[b]]+=t;
		int ma=find_root(mp[a]);//���ܸ�mp[a]!
		int mb=find_root(mp[b]);
		if(ma!=mb) {
			tree[ma]=mb;//�ϲ�
			sum[mb]+=sum[ma]+t;//һ���������ʱ��
		} else sum[ma]+=t; //sum[mb]Ҳ����
	}
//		for(int i=0;i<num;i++)
//			cout<<tim[i]<<' '<<sum[i]<<'\n';

	int c_num=0;//������
	for(int i=0; i<num; i++) {
		if(tree[i]==-1 && sum[i]>k)
			clus[c_num++].root=i;
	}
	for(int i=0; i<num; i++) {
		if(tree[i]!=-1) {
			int f=find_root(i);
			for(int j=0; j<c_num; j++) {
				if(f==clus[j].root) {
					clus[j].m.push_back(i);//��ÿ��clu����һ��
				}
			}
		}
	}

	int ok_num=0;//���������ļ�����
	for(int i=0; i<c_num; i++) {
		if(clus[i].m.size()>1) {//��2��������
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

