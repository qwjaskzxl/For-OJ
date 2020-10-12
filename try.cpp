#include<stdio.h>
#include<stdlib.h>
//#include<graphics.h>

struct Stu {
	int id;
	double sc;
} stu[999];
int sel,i=0,x,y,n;
double sum,ave=1,count=0,a[999];

void intput() {
	printf("\t������ѧ��������0-999����");
	scanf("%d",&n);
	printf("\t\tѧ��\t�ɼ�\n");
	do {
		printf("\t\t[%d]\t",i+1);
		scanf("%lf",&stu[i].sc);
		stu[i].id=++i;
	} while(i<n);
}

void cal_ave() {
	sum=0;
	for(i=0; i<n; i++)
		sum+=stu[i].sc;
	ave=sum/n;
	printf("\n\t\nƽ���ɼ�Ϊ%.1f\n",ave);
}

void cal_pass() {
	for(i=0; i<n; i++)
		if(stu[i].sc>=60)
			count++;
	printf("\n\t\n������Ϊ%.1f%%\n",count/n*100);
}

void find_stu_sc() {
	do {
		printf("����������ҵ�ѧ����ѧ�ţ�����Ƿ������˳�����");
		scanf("%d",&x);
		if(x>0&&x<=n)
			printf("\t[%d]\t%.1f\n",x,stu[x-1].sc);
		else
			break;
	} while(1);
}

void modi_sc() {
	printf("�޸�ѧ���ɼ�\n");
	do {
		printf("���������޸ĵ�ѧ����ѧ�ţ�����Ƿ������˳�����");
		scanf("%d",&y);
		if(y>0&&y<=n) {
			printf("\t[%d]\t%.1f\n",y,a[y-1]);
			printf("\t������Ķ���ķ�����");
			scanf("%lf",&a[y-1]);
		} else
			break;
	} while(1);
}

void save_sc() {
	FILE *fp=fopen("scores.txt","w");
	if (!fp) {
		printf("\t�ļ���ʧ�ܣ���鿴�ļ��Ƿ���ڻ�ռ��");
		return ;
	}
	char info[20]="ѧ�� �ɼ�\n";
	fputs(info,fp);
	for(int j=0; j<i; j++) {
		char id[5]= {char(stu[j].id+'0'),' '}, out[5];
		fputs(id,fp);
		itoa(stu[j].sc,out,3);
		fputs(out,fp);
		fputs("\n",fp);
	}
	fclose(fp);
	printf("����ɼ��ɹ���\n");
}

int main() {
//	initgraph(640, 480); // ��ʼ������ʾһ�����ڣ������ TC ��������
//	circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100
//	getch(); // ��ͣһ�µȴ��û�����
//	closegraph(); // �ر�ͼ�ν���
	do {
		printf("\t************************************\n");
		printf("\t*          ѧ���ɼ�����ϵͳ        *\n");
		printf("\t*                                  *\n");
		printf("\t*     ����ѧ���ɼ�---------1       *\n");
		printf("\t*     ͳ��ƽ���ɼ�---------2       *\n");
		printf("\t*     ͳ�Ƽ�����-----------3       *\n");
		printf("\t*     ����ѧ���ɼ�---------4       *\n");
		printf("\t*     �޸�ѧ���ɼ�---------5       *\n");
		printf("\t*     ����ѧ���ɼ�---------6       *\n");
		printf("\t*     �˳�ϵͳ-------------7       *\n");
		printf("\t*                                  *\n");
		printf("\t************************************\n\n");
		printf("\t������ѡ�1-7����");
		scanf("%d",&sel);
		switch(sel) {
			case 1:
				intput();
				break;
			case 2:
				cal_ave();
				break;
			case 3:
				cal_pass();
				break;
			case 4:
				find_stu_sc();
				break;
			case 5:
				modi_sc();
				break;
			case 6:
				save_sc();
				break;
			case 7:
				printf("�˳�ϵͳ��");
				break;
			default:
				printf("�������\n");
				break;
		}
	} while(sel>0&&sel!=7);
}
