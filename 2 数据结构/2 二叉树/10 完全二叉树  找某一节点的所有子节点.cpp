#include<iostream>
#include<cmath>//pow在这里 
#include<algorithm>//min在这里 
using namespace std;
typedef long long ll;
ll delta_l;//l1 l2都不要，只要知道差就行啦
ll pow_delta_l;//2^delta_l 这个会多次用到 
ll m,n,lastn;//要查元素序号，最大元素序号，求要查元素的子树中最大的元素序号（也就是在l2层上最大的序号

int main() {
	while(cin>>m>>n, m!=0) {
		ll sum=0;
		delta_l=ll(log(n*1.0/m)/log(2));//这个不能在ll外打括号！不然只是单纯的类型变了，值还是错的？？
		pow_delta_l=pow(2,delta_l);
		lastn=m*pow_delta_l+pow_delta_l-1;//先根据2次方关系，算到最下面一层的第一个元素，然后加上剩下的元素书
		if(n>=lastn) sum=2*pow_delta_l-1;//等比数列的n是元素数量，不是差值
		else {
			sum+=pow_delta_l-1;//a1*(1-q^n)/(1-q)化简
			sum+=n-m*pow_delta_l+1;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
