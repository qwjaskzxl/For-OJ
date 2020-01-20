/*
����һ��m��n�е��ַ�����ֻҪ��������@�����ھ������һ����ͨ�飬
��������ַ�������2����ͨ��

****@
*@@*@
*@**@
@@@*@
@@**@

������ 
���ַ�������һ��ͼ����DFS��ͼ�е��ַ�������
��ÿ����@��������������@����Χ���ַ���
ÿ�η���ʱ����λ�ô��Ͽ��־����ʾ�ѷ��ʣ��Ӷ������η���ͬһ��λ�á�

*/

#include<bits/stdc++.h>
#define maxn 12
using namespace std;
int m,n;
char Map[maxn][maxn];
int vst[maxn][maxn]; 
int Next[8][2]={0,1,0,-1,1,0,-1,0};//ע�⣡����ߵ� б�Ų�������ͨ 
void DFS(int x,int y,int index){
    int dr,dc;
    //�����߽磬���� 
    if(x < 0 || x > m+1 || y < 0 || y > n+1)//Map�Ǵ�0��ʼ�� 
        return;
    //������ͨ�����ɲ��ֻ��ѷ���,����
    if(Map[x][y] != '_' || vst[x][y] >0)
        return;
    //�Է��������Ŀ�ʼ����
    vst[x][y] = index;
    for(int i=0;i<4;i++)
    {
    	int nx=x+Next[i][0];
    	int ny=y+Next[i][1];
    	DFS(nx,ny,index);
	}
}
int main()
{	
    int i,j;
    int T=1;cin>>T;
    while(T--)
    {
	    m=n=10;
	    memset(Map,'_',sizeof(Map));
	    memset(vst,0,sizeof(vst));
	    for(i = 1; i <= m; i++)
	    for(j = 1; j <= n; j++)
	        cin>>Map[i][j];
	  	  
	    int cnt = 0;
	    for(i = 0; i <= m+1; i++)	//�ڴ���Ȧ�� 
	    for(j = 0; j <= n+1; j++)		
	        if(Map[i][j] == '_' && vst[i][j] == 0) //���Ͽ�������δ���ʹ�                
	    		DFS(i,j,++cnt);//�ҵ��µļ���DFS 
				               
	    //cout<<cnt<<endl;
	    switch(cnt)
	    {
	    	case 1:cout<<1<<endl;break;
	    	case 2:cout<<0<<endl;break;
	    	case 3:cout<<8<<endl;break;
		}
	}
    return 0;
} 
