#include<iostream>
#include<cstring>
using namespace std;
struct node {
	char data;//����Ҫ�����������
	node *lchild;
	node *rchild;
	int layer;//��ʱ����Ҫ֪��������eg��α�����������ʱ����Ҫ
};//��������������
string str1,str2;//�ֱ��ǰ�б������ַ���

node *creat() {
	node *T=new node;//һ��Ҫnew����˼�Ƿ����ڴ� 
	T->lchild=T->rchild=NULL;//��������Ϊ��
	return T;
}

void post_order(node *T) {//T��������ָ��
	if(T->lchild!=NULL)//����дT.lchild����ΪT��ָ�������->,������ָ�������T.xxx 
		post_order(T->lchild);
	if(T->rchild!=NULL)
		post_order(T->rchild);
	printf("%c", T->data);
}

node *build(int s1,int e1, int s2,int e2) {//str1��[s1,e1]Ϊǰ��str2��[s2,e2]Ϊ���� 
	node *T=creat();
	T->data=str1[s1];//ǰ������ĵ�һ���ַ���root
	int rootidx;//root��str2��λ��
	for(int i=s2; i<=e2; i++) {
		if(str2[i]==T->data) {
			rootidx=i;
			break;
		}
	}
	//����������������ж����������Ƿ�Ϊ�ա�	
	if(rootidx!=s2) //��rootidx��������ߵ�Ԫ�أ�˵��û���������� 
		//rootidx-s2�������������г���
		T->lchild=build(s1+1,s1+(rootidx-s2), s2,rootidx-1);
	if(rootidx!=e2)
		T->rchild=build(s1+1+(rootidx-s2),e1, rootidx+1,e2);
	return T;
}

int main() {
	while(cin>>str1>>str2) {
		node *T=build(0,str1.length()-1, 0,str2.length()-1);//build���൱�ڽ�ԭ��������Tree�������� 
		post_order(T);//T���������root�ĵ�ַ 
		printf("\n");
	}
	return 0;
}
