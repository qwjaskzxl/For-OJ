#include<iostream>
using namespace std;
int main() {//10:43->10:51
//c必须是1或6
	for(int x=101; x<=432; x+=5) {
		for(int y=111; y<=432; ) {
			if(x+y==532 && x%10==y%10 && x/10%10==y/100)
				printf("%d %d %d\n",x/100,y/100,x%10);
			if(y%10==1) y+=55;
			else y+=45;
		}
	}
	return 0;
}

//法2 
#include<stdio.h>
int main() {
	int a,b,c;
	for(a=0; a<10; a++) {
		for(b=0; b<10; b++) {
			for(c=0; c<10; c++) {
				if(a*100+b*10+c + b*100+c*10+c == 532	) {
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
	return 0;
}

