/*
��Ŀ������
X ����һ������ʹ����������·�������ɸ��ڵ㡣�ڵ���ͨ����˫��ġ�
ĳ��Ҫ���ݰ���Ϊ�˰�ȫ���������ǡ�ñ�ת�����ε���Ŀ�ĵء�
�ð�����������һ���ڵ������������Ҫ֪����������һ���ж����ֲ�ͬ��ת��·����
Դ��ַ��Ŀ���ַ������ͬ�����м�ڵ���벻ͬ�� 
��ͼ����дͼƬ������ʾ�����硣
1 -> 2 -> 3 -> 1 ������� 1 -> 2 -> 1 -> 2 ���� 1 -> 2 -> 3 -> 2 ���ǷǷ��ġ�

���룺
�������ݵĵ�һ��Ϊ��������N M���ֱ��ʾ�ڵ������������·������(1<=N<=10000; 0<=M<=100000)�� ����ȥ��M�У�ÿ��Ϊ�������� u �� v����ʾ�ڵ�u �� v ��ͨ(1<=u,v<=N , u!=v)�� �������ݱ�֤�����������ֻ��һ�������ӣ�����û���Լ����Լ��ıߣ����������رߺ��Ի���

�����
���һ����������ʾ����Ҫ���·��������
*/
//#include<iostream>
//#include<cstdio>
//#include<vector>
//using namespace std;
//const int N=10009;
//vector<int> map[N];
//int n,m;
//int main()
//{
//    cin>>n>>m;
//    int i,j,k;
//    int ai,aj;
//    for(i=0;i<m;i++)
//    {
//        cin>>ai>>aj;
//        map[ai].push_back(aj);//˫����ͨ
//        map[aj].push_back(ai);
//    }
//    int count=0 ;
//    for(i=1; i<=n; i++)//��ʾ��i���ڵ�
//    {
//        for(j=0; j< map[i].size(); j++)//��һ����
//        {
//            for(k=0; k<map[map[i][j]].size(); k++)//��2����
//            {
//                if(map[map[i][j]][k]!=i)//�������㲻���ڵ�һ���㣬�����ɻ�·�������Ѱ�ҵ��ĸ���
//                    {
//                       int dk=map[map[i][j]][k];//��  Ϊ��������
//                       for(int d=0; d<map[dk].size(); d++)//ѭ���ҵ��ĸ��㣬�Ҳ����ڵڶ����㣻����ת����2��3���Ĵ��ս�
//                       {
//                            if( map[i][j]!= map[dk][d] )
//                            {
//                                count++;
//                            }
//                       }
//                    }
//            }
//        }
//    }
//    cout<<count<<endl;
//    return 0;
//}
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<string.h>  
#include<vector>  
using namespace std;  
struct st  
{  
    vector<int> arr;  
}map[10001];  
int n,m,b[5],cnt=0;  
  
void dfs(int x, int num)//xΪ�ҵ� ��·�� ��num�ǳ����㣬Ҳ���´�Ҫ�ߵĵ�    
{  
    int i,j,k;  
    if (x > 4 )  
    {  
        if (b[2]!=b[3] && b[2]!=b[1] &&b[2]!=b[4] && b[3]!=b[1] && b[3]!=b[4])  
        cnt++;  
        return ;  
    }  
    for (i=0; i<map[num].arr.size(); i++)//��������Ҫ��ѭ��  
    {  
        b[x] = map[num].arr[i];  
        dfs(x+1,map[num].arr[i]);   
    }  
}  
int main()  
{  
    int x,y,i,j,k;  
    cin>>n>>m;  
    for (i=1; i<=m; i++)  
    {  
        scanf("%d%d",&x,&y);  
        map[x].arr.push_back(y);  
        map[y].arr.push_back(x);  
    }  
    for (i=1; i<=n; i++)  
    {  
        b[1] = i;  
        dfs(2,i);//Ѱ�� ��i������·   
    }  
    cout<<cnt;  
    return 0;  
}   
