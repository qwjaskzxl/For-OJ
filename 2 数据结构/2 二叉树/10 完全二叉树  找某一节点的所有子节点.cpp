#include<iostream>
#include<cmath>//pow������ 
#include<algorithm>//min������ 
using namespace std;
typedef long long ll;
ll delta_l;//l1 l2����Ҫ��ֻҪ֪���������
ll pow_delta_l;//2^delta_l ��������õ� 
ll m,n,lastn;//Ҫ��Ԫ����ţ����Ԫ����ţ���Ҫ��Ԫ�ص�����������Ԫ����ţ�Ҳ������l2�����������

int main() {
	while(cin>>m>>n, m!=0) {
		ll sum=0;
		delta_l=ll(log(n*1.0/m)/log(2));//���������ll������ţ���Ȼֻ�ǵ��������ͱ��ˣ�ֵ���Ǵ�ģ���
		pow_delta_l=pow(2,delta_l);
		lastn=m*pow_delta_l+pow_delta_l-1;//�ȸ���2�η���ϵ���㵽������һ��ĵ�һ��Ԫ�أ�Ȼ�����ʣ�µ�Ԫ����
		if(n>=lastn) sum=2*pow_delta_l-1;//�ȱ����е�n��Ԫ�����������ǲ�ֵ
		else {
			sum+=pow_delta_l-1;//a1*(1-q^n)/(1-q)����
			sum+=n-m*pow_delta_l+1;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
