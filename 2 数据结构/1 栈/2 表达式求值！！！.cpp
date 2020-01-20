#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node {
	double n;//值
	char op;//操作符
	int f;//用于cal：1是数字，0是op。后缀表达式没有括号
};

string str;
stack<node>s;//char类型也无法存储长数字，除非用两个栈
queue<node>q;
map<char,int> opm;//操作符优先级的映射

void change() {
	double n;
	node t;
	for(int i=0; i<str.length(); ) {
		if(str[i]>='0' && str[i]<='9') {
			t.f=1;//是数字
			t.n=str[i++]-'0';
			while(i<str.length() && str[i]>='0' && str[i]<='9') { //把完整的数字读入
				t.n=t.n*10+(str[i++]-'0');//so目前程序不能处理小数。
				//若想处理小数，则遇到小数点后的数字就要每次乘以0.1加到原数即可
			}
			q.push(t);
		} else if(str[i]=='(') { //包括下面，忘记i++了，没往下走，导致内存爆炸
			t.op='(';
			s.push(t);
			i++;
		} else if(str[i]==')') {
			while(!s.empty() && s.top().op!='(') { //好像这里不需要判空
				q.push(s.top());
				s.pop();
			}
			s.pop();//把左括号出栈
			i++;
		} else {
			t.f=0;//是op
//			if(opm[str[i]] <= opm[s.top().op])//为什么加上会报错？虽然没必要这句，但是也不应该报错啊
			while(!s.empty() && opm[str[i]] <= opm[s.top().op]) { //栈顶优先级不低，就要先出栈，因为同级的也是先进的先算，也要出栈。一定不要忘了判空！
				q.push(s.top());
				s.pop();
			}
			t.op=str[i++];//是左括号或优先级高于栈顶都入栈，其他的最终也要入栈
			s.push(t);//so 各种情况最后 都要入栈
		}
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}
void show_exp() {
	queue<node>p=q;//不然把q清空了，后面没法算
	while(!p.empty()) {
		if(p.front().f==1)
			cout<<p.front().n<<" ";
		else if(p.front().f==0)
			cout<<p.front().op<<" ";
		p.pop();
	}
	cout<<endl;
}
double cal() {
	node t;
	while(!q.empty()) {
		if(q.front().f==1) { //是数字
			s.push(q.front());
		}

		if(q.front().f==0) { //是op
			double t2=s.top().n;//先出栈的后运算！！
			s.pop();
			double t1=s.top().n;
			s.pop();
			if(q.front().op=='+') t.n=t1+t2;
			if(q.front().op=='-') t.n=t1-t2;
			if(q.front().op=='*') t.n=t1*t2;
			if(q.front().op=='/') t.n=t1/t2;
			t.f=1;//ans就是数字
			s.push(t);
		}
		q.pop();
	}
	return s.top().n;
}

int main() {
	opm['(']=0;//因为遇到左括号都入栈
	opm['+']=opm['-']=1;
	opm['*']=opm['/']=2;
	while(getline(cin,str), str!="0") { //是0时，程序结束
		for(string::iterator it=str.end(); it!=str.begin(); it--) { //去掉空格。倒着，因为最后有空格，起始没有
			if(*it==' ') str.erase(it);//不用迭代器 用index也可以用位置erase
		}
		while(!s.empty()) s.pop();
		change();
		show_exp();
		printf("%.2lf\n", cal());
	}
	return 0;
}
