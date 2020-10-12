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
	printf("\t请输入学生人数（0-999）：");
	scanf("%d",&n);
	printf("\t\t学号\t成绩\n");
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
	printf("\n\t\n平均成绩为%.1f\n",ave);
}

void cal_pass() {
	for(i=0; i<n; i++)
		if(stu[i].sc>=60)
			count++;
	printf("\n\t\n及格率为%.1f%%\n",count/n*100);
}

void find_stu_sc() {
	do {
		printf("请输入需查找的学生的学号（输入非法数据退出）：");
		scanf("%d",&x);
		if(x>0&&x<=n)
			printf("\t[%d]\t%.1f\n",x,stu[x-1].sc);
		else
			break;
	} while(1);
}

void modi_sc() {
	printf("修改学生成绩\n");
	do {
		printf("请输入需修改的学生的学号（输入非法数据退出）：");
		scanf("%d",&y);
		if(y>0&&y<=n) {
			printf("\t[%d]\t%.1f\n",y,a[y-1]);
			printf("\t请输入改动后的分数：");
			scanf("%lf",&a[y-1]);
		} else
			break;
	} while(1);
}

void save_sc() {
	FILE *fp=fopen("scores.txt","w");
	if (!fp) {
		printf("\t文件打开失败，请查看文件是否存在或被占用");
		return ;
	}
	char info[20]="学号 成绩\n";
	fputs(info,fp);
	for(int j=0; j<i; j++) {
		char id[5]= {char(stu[j].id+'0'),' '}, out[5];
		fputs(id,fp);
		itoa(stu[j].sc,out,3);
		fputs(out,fp);
		fputs("\n",fp);
	}
	fclose(fp);
	printf("保存成绩成功！\n");
}

int main() {
//	initgraph(640, 480); // 初始化，显示一个窗口，这里和 TC 略有区别
//	circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
//	getch(); // 暂停一下等待用户按键
//	closegraph(); // 关闭图形界面
	do {
		printf("\t************************************\n");
		printf("\t*          学生成绩管理系统        *\n");
		printf("\t*                                  *\n");
		printf("\t*     输入学生成绩---------1       *\n");
		printf("\t*     统计平均成绩---------2       *\n");
		printf("\t*     统计及格率-----------3       *\n");
		printf("\t*     查找学生成绩---------4       *\n");
		printf("\t*     修改学生成绩---------5       *\n");
		printf("\t*     保存学生成绩---------6       *\n");
		printf("\t*     退出系统-------------7       *\n");
		printf("\t*                                  *\n");
		printf("\t************************************\n\n");
		printf("\t请输入选项（1-7）：");
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
				printf("退出系统！");
				break;
			default:
				printf("输入错误！\n");
				break;
		}
	} while(sel>0&&sel!=7);
}
