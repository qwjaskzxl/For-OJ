#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_map>
#include<map>
#include<bits/stdc++.h>
using namespace std;

int isPrime(long long x) {
	int k=sqrt(x);
	for(int i=2; i<=k; i++) {
		if(x%i==0) return 0;
	}
	return 1;
}
unordered_map<int,int>mp;
unordered_map<int,int>::iterator it;
//�������ȫ������map����ΪҪ������������е�
int main() {
	long long n=18;
//	cin>>n;
	while(!isPrime(n)){
		mp.clear();//һ���ǵ�clear 
		int t=n;
		for(int i=2; i<n&&t>0; i++) {
//		cout<<i<<' '<<t<<'\n';
			while(t%i==0) {
				if(!mp[i]) {
					mp[i]=1;
					t/=i;
				} else {
					mp[i]++;
					t/=i;
				}
			}
		}
		string s;
		vector<string>tmp;
		for(it=mp.begin(); it!=mp.end(); it++) {
//		cout<<it->first<<' '<<it->second<<endl;
			if(it->second==1) {
				tmp.push_back(to_string(it->first));
			} else {
				tmp.push_back(to_string(it->second));//ָ��
				tmp.push_back(to_string(it->first));//����
			}
		}
		for(int i=tmp.size()-1; i>=0; i--) {
			s+=tmp[i];
		}
		n=stoll(s);
//		cout<<n;
	}
	cout<<n;
	return 0;
}
/*
18
ans:17137
*/
