//���������εĳ��Ϳ�ÿ�δӳ�������˺ȥ���������Σ��������ܵõ�����������
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
