#include<iostream>
using namespace std;
int F(int x) {
	int ans=0;
	while(x) {
		ans+=x%10;
		x/=10;
	}
	if(ans<10) {
		return ans;
	} else return F(ans);//Ӧ��Ҫдreturn����Ϊ�ݹ���F��������ֵ������Ҫ��������return��main��
						//���ǲ�дΪɶҲ�ܵõ�ans��? ������ţ��OJͨ���ʾ�Ϊ 0%�� 
}
int main() { //��17:52->18:01
	int x;
	while(scanf("%d", &x)!=EOF) {
		printf("%d\n", F(x));
//		printf("%d\n", (x+8)%9+1);
	}
	return 0;
}

//��2��ѭ����
#include <iostream>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF,n!=0){
        int a,b;
        while(n>=10){
        	a=n%10;
        	b=n/10;
        	n=a+b;
        }
        cout<<n<<endl;
    }
    return 0;
}
