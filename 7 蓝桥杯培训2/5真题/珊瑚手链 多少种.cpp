/*
有3颗红珊瑚，4颗白珊瑚，5颗黄玛瑙，用它们串成一圈作为手链。 
如果考虑手链可以随意转动或翻转，一共可以有多少不同的组合样式呢？
*/

//可翻转其实就是，能reverse，不信试试 

/*
暴力的思路：不过很棒！ 

这个题，主要运用stl中的
string.find(str),
next_permutation(str.begin(),str.end()),
reverse(str.begin,str.end())。
在一个vector中存下已经出现过的排列，
每一个排列先在vector中查找是否已存在该排列，
若不存在，则res++，
并将str+str(可任意转动)和reverse(str.begin(),str.end()) (可任意翻转) 
压入vector。
这样的话，比较花时间，但是可以接受。
*/

#include<bits/stdc++.h>
using namespace std;
vector<string> vec;
int main()
{
    string str="AAABBBBCCCCC";
    int res=0;
    do
    {
        int flag=1;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i].find(str)!=string::npos) //查找 a是否包含子串b的写法 
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            res++;
            string tmp=str+str;//因为是环。。所以这样相当于连起来了 
            vec.push_back(tmp);
            reverse(tmp.begin(),tmp.end());
            vec.push_back(tmp);
        }
    }while(next_permutation(str.begin(),str.end()));
    cout<<res<<endl;
    return 0;
}

/*
使用用数学方法计算
12！/（3！*4！*5！*12）=2310种，这是不考虑可以翻转的答案。
若考虑翻转需要求出那些左右对称的情况，
将1个A，1个C两边都隔5个，剩下2个A，4个B，4个C，两边对称，
即将ABBCC排列，共5！/（2*2）=30种。
所以最终结果是30+（2310-30）/2=1170。
*/
