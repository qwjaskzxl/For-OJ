#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node {
	double n;//ֵ
	char op;//������
	int f;//����cal��1�����֣�0��op����׺���ʽû������
};

string str;
stack<node>s;//char����Ҳ�޷��洢�����֣�����������ջ
queue<node>q;
map<char,int> opm;//���������ȼ���ӳ��

void change() {
	double n;
	node t;
	for(int i=0; i<str.length(); ) {
		if(str[i]>='0' && str[i]<='9') {
			t.f=1;//������
			t.n=str[i++]-'0';
			while(i<str.length() && str[i]>='0' && str[i]<='9') { //�����������ֶ���
				t.n=t.n*10+(str[i++]-'0');//soĿǰ�����ܴ���С����
				//���봦��С����������С���������־�Ҫÿ�γ���0.1�ӵ�ԭ������
			}
			q.push(t);
		} else if(str[i]=='(') { //�������棬����i++�ˣ�û�����ߣ������ڴ汬ը
			t.op='(';
			s.push(t);
			i++;
		} else if(str[i]==')') {
			while(!s.empty() && s.top().op!='(') { //�������ﲻ��Ҫ�п�
				q.push(s.top());
				s.pop();
			}
			s.pop();//�������ų�ջ
			i++;
		} else {
			t.f=0;//��op
//			if(opm[str[i]] <= opm[s.top().op])//Ϊʲô���ϻᱨ����Ȼû��Ҫ��䣬����Ҳ��Ӧ�ñ���
			while(!s.empty() && opm[str[i]] <= opm[s.top().op]) { //ջ�����ȼ����ͣ���Ҫ�ȳ�ջ����Ϊͬ����Ҳ���Ƚ������㣬ҲҪ��ջ��һ����Ҫ�����пգ�
				q.push(s.top());
				s.pop();
			}
			t.op=str[i++];//�������Ż����ȼ�����ջ������ջ������������ҲҪ��ջ
			s.push(t);//so ���������� ��Ҫ��ջ
		}
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}
void show_exp() {
	queue<node>p=q;//��Ȼ��q����ˣ�����û����
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
		if(q.front().f==1) { //������
			s.push(q.front());
		}

		if(q.front().f==0) { //��op
			double t2=s.top().n;//�ȳ�ջ�ĺ����㣡��
			s.pop();
			double t1=s.top().n;
			s.pop();
			if(q.front().op=='+') t.n=t1+t2;
			if(q.front().op=='-') t.n=t1-t2;
			if(q.front().op=='*') t.n=t1*t2;
			if(q.front().op=='/') t.n=t1/t2;
			t.f=1;//ans��������
			s.push(t);
		}
		q.pop();
	}
	return s.top().n;
}

int main() {
	opm['(']=0;//��Ϊ���������Ŷ���ջ
	opm['+']=opm['-']=1;
	opm['*']=opm['/']=2;
	while(getline(cin,str), str!="0") { //��0ʱ���������
		for(string::iterator it=str.end(); it!=str.begin(); it--) { //ȥ���ո񡣵��ţ���Ϊ����пո���ʼû��
			if(*it==' ') str.erase(it);//���õ����� ��indexҲ������λ��erase
		}
		while(!s.empty()) s.pop();
		change();
		show_exp();
		printf("%.2lf\n", cal());
	}
	return 0;
}
