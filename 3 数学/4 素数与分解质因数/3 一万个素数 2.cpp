#include<iostream>
#include<cstring>
#include<cmath>
typedef unsigned long long LL;
using namespace std;
LL prime[10005];//����ɸ��������
int pri_n=0;//��������
int mark[100005];//1���ѱ�� �������ж����Ƿ�Ϊ����
void search_prime() {//��ɸ��O(nloglogn)
	memset(mark,0,sizeof(mark));
	for(LL i=2; i<=104740; i++) {//���ֻ��46000�������������Ϊ46*46=2116�쵽��int���Χ
		if(mark[i]) continue;//�ѱ��
		prime[pri_n++]=i;
		for(LL k=i*i; k<=100000; k+=i)//�����ı�����������ѷ��ʣ������Ƿ�����
			mark[k]=1;		 
	}
//	cout<<pri_n;
//	for(int i=0; i<pri_n; i++)
//		cout<<prime[i]<<' ';
}
int main() {
	search_prime();
	int n;//2<=n<=10000
	while(cin>>n) {
		printf("%d\n", prime[n-1]);
	}
	return 0;
}
