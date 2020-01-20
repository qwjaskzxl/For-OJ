#include<iostream>
#include<cstring>
using namespace std;
struct node {
	char data;//根据要求改数据类型
	node *lchild;
	node *rchild;
	int layer;//有时候需要知道层数，eg层次遍历。本题暂时不需要
};//用来保存整棵树
string str1,str2;//分别放前中遍历的字符串

node *creat() {
	node *T=new node;//一定要new，意思是分配内存 
	T->lchild=T->rchild=NULL;//左右子树为空
	return T;
}

void post_order(node *T) {//T是树根的指针
	if(T->lchild!=NULL)//不能写T.lchild，因为T是指针必须用->,若不是指针可以用T.xxx 
		post_order(T->lchild);
	if(T->rchild!=NULL)
		post_order(T->rchild);
	printf("%c", T->data);
}

node *build(int s1,int e1, int s2,int e2) {//str1中[s1,e1]为前序，str2中[s2,e2]为中序 
	node *T=creat();
	T->data=str1[s1];//前序遍历的第一个字符是root
	int rootidx;//root在str2的位置
	for(int i=s2; i<=e2; i++) {
		if(str2[i]==T->data) {
			rootidx=i;
			break;
		}
	}
	//利用中序遍历，来判断左右子树是否为空。	
	if(rootidx!=s2) //若rootidx就是最左边的元素，说明没有左子树了 
		//rootidx-s2就是左子树序列长度
		T->lchild=build(s1+1,s1+(rootidx-s2), s2,rootidx-1);
	if(rootidx!=e2)
		T->rchild=build(s1+1+(rootidx-s2),e1, rootidx+1,e2);
	return T;
}

int main() {
	while(cin>>str1>>str2) {
		node *T=build(0,str1.length()-1, 0,str2.length()-1);//build后，相当于将原数保存在Tree数组中了 
		post_order(T);//T是这棵树的root的地址 
		printf("\n");
	}
	return 0;
}
