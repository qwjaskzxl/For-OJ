/*
考虑一种简单的正则表达式： 只由 x ( ) | 组成的正则表达式。 
小明想求出这个正则表达式能接受的最长字符串的长度。 
例如 ((xx|xxx)x|(x|xx))xx 能接受的最长字符串是： xxxxxx，长度是6。
输入
一个由x()|组成的正则表达式。输入长度不超过100，保证合法。
输出
这个正则表达式能接受的最长字符串的长度。

输入
((xx|xxx)x|(x|xx))xx
输出
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
