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
	} else return F(ans);//应该要写return，因为递归后的F，得来的值，还是要经过这里return回main。
						//但是不写为啥也能得到ans呢? 不过在牛客OJ通过率就为 0%了 
}
int main() { //我17:52->18:01
	int x;
	while(scanf("%d", &x)!=EOF) {
		printf("%d\n", F(x));
//		printf("%d\n", (x+8)%9+1);
	}
	return 0;
}

//法2：循环法
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
