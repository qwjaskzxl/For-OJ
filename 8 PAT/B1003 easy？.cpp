#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	string a;

	while(T--) {
		cin>>a;
		int L=a.length();
		int x=0,y=0,z=0,j=0;
		for(int i=0; i<L; i++) {
			if(a[i]!='P'&&a[i]!='A'&&a[i]!='T') 
				break;
			if(j==0) {
				if(a[i]=='P') {
					j++;
				} 
				else
					for(; a[i]=='A'&&i<L; i++,x++)
						if(a[i+1]=='P') {
							j=1;
						}
			}
			else if(j==1) {
				for(; a[i]=='A'&&i<L; i++,y++) {
					if(a[i+1]=='T') {
						j=2;
					}
				}
			}
			else if(j==2) {
				for(; a[i]=='A'&&i<L; i++,z++);
			}
		}
		if(j==2&&x*y==z) printf("YES");
		else printf("NO");
		if(T!=0) printf("\n");
	}
	return 0;
}
