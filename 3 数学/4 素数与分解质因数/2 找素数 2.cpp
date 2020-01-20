#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int prime[10005];//����ɸ��������
int pri_n=0;//��������
int mark[10005];//1���ѱ�� �������ж����Ƿ�Ϊ����
void search_prime() {//��ɸ��O(nloglogn)
	memset(mark,0,sizeof(mark));
	for(int i=2; i<=10000; i++) {//���ֻ��46000�������������Ϊ46*46=2116�쵽��int���Χ
		if(mark[i]) continue;//�ѱ��		
		prime[pri_n++]=i;//û��ǵ��ģ�һ�������� 
		for(int k=i*i; k<=10000; k+=i)//�����ı�����������ѷ��ʣ������Ƿ�����
			mark[k]=1;		
	}
//	for(int i=0; i<pri_n; i++)
//		cout<<prime[i]<<' ';
}
int main() {
	search_prime();
	int n, i, ok;//2<=n<=10000
	while(cin>>n) {
		for(i=0,ok=0; n>prime[i]; i++) {
			if(prime[i]%10==1) {
				printf("%d ", prime[i]);
				ok=1;
			}
		}
		if (ok) printf("\n");
		else printf("-1\n");
	}
	return 0;
}
