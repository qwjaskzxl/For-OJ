#include<iostream>
using namespace std;
const int N=1005;
int w[N];//����
int v[N];//����
int dp[N][N];//dpij��ʾ���<=jʱ��ǰi����Ʒ�ﵽ���������
int W,n;//��������Ʒ��
void show_dp() {
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=W; j++)
			cout<<dp[i][j]<<' ';
		cout<<"\n";
	}
	cout<<"\n";
}
int main() {

	while(cin>>W>>n) {
		if(!W && !n) break;
		for(int i=1; i<=n; i++)//�����1��ʼ����Ϊ0�С�ûѡ��Ʒ���ĺ��壬����ȱ�٣�
			cin>>w[i]>>v[i];
		for(int j=0; j<=W; j++) dp[0][j]=0;//ûѡ�Ļ�������0 
		for(int i=1; i<=n; i++) {
			for(int j=w[i]; j<=W; j++)//��װ 
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
			for(int j=w[i]-1; j>=0; j--)//����װ 
				dp[i][j]=dp[i-1][j];
//			show_dp();
		}
		cout<<dp[n][W]<<endl;
	}
	return 0;
}

/*
5 3
3 2
2 4
3 3
*/

#include<iostream>
using namespace std;
const int N=1005;
int w[N];//����
int v[N];//����
int dp[N];//���<=jʱ���ܴﵽ���������
int W,n;//��������Ʒ��
void show_dp() {
	for(int j=0; j<=W; j++)
		cout<<dp[j]<<' ';
	cout<<"\n\n";
}
int main() {
	
	while(cin>>W>>n) {
		if(!W && !n) break;
		for(int i=1; i<=n; i++)//�����1��ʼ����Ϊ0�С�ûѡ��Ʒ���ĺ��壬����ȱ�٣�
			cin>>w[i]>>v[i];
		for(int j=0; j<=W; j++) dp[j]=0; //ҲҪ��init=0�����Ϊ�����ʱ��ά��ȥ�ˣ�
		//������ʵ�տ�ʼ��Ҫȫ����Ϊ0����ʾ��ʱ��ά�ȵ����壬����ûѡ��ʱ�����涼��0
		for(int i=1; i<=n; i++) {
			for(int j=W; j>=w[i]; j--)
				dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
//			show_dp();
		}
		cout<<dp[W]<<endl;
	}
	return 0;
}
