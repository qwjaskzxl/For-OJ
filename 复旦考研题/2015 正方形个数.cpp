//给出长方形的长和宽，每次从长方形里撕去最大的正方形，输出最后能得到多少正方形
#include<bits/stdc++.h>
using namespace std;
void square_cnt(int l, int w) {
    int cnt = 0;
    while (l > w) {
        l -= w;
        cnt++;
        if (l < w) swap(l,w);
    }
    printf("%d", cnt + 1); //l=w(+1)
}

int main() 
{
	square_cnt(4,2);
	return 0;
}
