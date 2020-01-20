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
#define maxn 10
using namespace std;
int m,n;
char Map[maxn][maxn];
int vst[maxn][maxn]; 
int Next[8][2]={0,1,0,-1, 1,1,1,-1, 1,0,-1,0,-1,-1,-1,1};
void DFS(int x,int y,int index){
    int dr,dc;
    //�����߽磬���� 
    if(x < 0 || x >= m || y < 0 || y >=n)//Map�Ǵ�0��ʼ�� 
        return;
    //������ͨ�����ɲ��ֻ��ѷ���,����
    if(Map[x][y] != '@' || vst[x][y] >0)
        return;
    //�Է��������Ŀ�ʼ����
    vst[x][y] = index;
    for(int i=0;i<8;i++)
    {
    	int nx=x+Next[i][0];
    	int ny=y+Next[i][1];
    	DFS(nx,ny,index);
	}
//    for(dr = -1; dr <= 1; dr++)
//	{
//        for(dc = -1; dc <= 1; dc++)
//		{
//            if(dr != 0 || dc != 0)
//			{
//                DFS(x+dr,y+dc,index);
//            }
//        }
//    }
}
int main()
{
    int i,j;
    cin>>m>>n;
    for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
        cin>>Map[i][j];
  
    memset(vst,0,sizeof(vst));
    int cnt = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(Map[i][j] == '@' && vst[i][j] == 0){ //���Ͽ�������δ���ʹ� 
                //�ҵ�һ���µ� 
                DFS(i,j,++cnt); 
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
} 
