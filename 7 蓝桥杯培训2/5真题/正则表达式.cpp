/*
����һ�ּ򵥵�������ʽ�� ֻ�� x ( ) | ��ɵ�������ʽ�� 
С����������������ʽ�ܽ��ܵ���ַ����ĳ��ȡ� 
���� ((xx|xxx)x|(x|xx))xx �ܽ��ܵ���ַ����ǣ� xxxxxx��������6��
����
һ����x()|��ɵ�������ʽ�����볤�Ȳ�����100����֤�Ϸ���
���
���������ʽ�ܽ��ܵ���ַ����ĳ��ȡ�

����
((xx|xxx)x|(x|xx))xx
���
6
*/

#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
char s[200];  
int len = 0,pos = 0;   
int dfs(){  
    int xnum = 0;  
    int maxx = 0;  
    while(pos < len){  
        if(s[pos] == '('){  
            pos++;  
            xnum += dfs();  
        }  
        else if(s[pos] == ')'){  
            pos++;  
            break;    
        }
        else if(s[pos] == '|'){  
            pos++;  
            maxx = max(xnum,maxx);  
            xnum = 0;  
        }  
        else {  
            pos++;  
            xnum ++;  
        }  
    }  
    maxx = max(xnum,maxx);  
    return maxx;
}  
int main(){  
    cin >> s;  
    len = strlen(s);  
    int ans = 0;  
    ans = dfs();  
    printf("%d\n",ans);  
}  
