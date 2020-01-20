/*
#include<iostream>
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n)!=EOF) {
		int xn=min(n/5,100);
		int yn=min(n/3,100);
		int zn=min(3*n,100);
		for(int x=0; x<=xn; x++)
			for(int y=0; y<=yn; y++)
				for(int z=0; z<=zn; z++) {
					if(x+y+z==100 && 5*x+3*y+(z+2)/3<=n)
						printf("x=%d,y=%d,z=%d\n", x,y,z);
				}
	}
	return 0;
}
*/
//二重循环的：

#include<iostream>
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n)!=EOF) {
		int xn=min(n/5,100);
		int yn=min(n/3,100);
		int zn=min(3*n,100);
		for(int x=0; x<=xn; x++)//	<=100
			for(int y=0; y<=yn; y++) {//	<=100-x
				int z=100-x-y;
				if(z>=0&&x*15+y*9+z<=n*3)
					printf("x=%d,y=%d,z=%d\n", x,y,z);
			}
	}
	return 0;
}
