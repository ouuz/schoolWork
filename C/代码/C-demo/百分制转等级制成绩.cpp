//百分制成绩转换等级制
#include <stdio.h>
int main ()
{
	int grade;
	char level;
	printf("请输入一个百分制成绩:\n");
	scanf("%d", &grade);
	switch(grade/10)
	{
		case 10:
		case 9 :
			level = 'A';
			break;
		case 8 :
			level = 'B';
			break;
		case 7 :
			level = 'C';
			break;
		case 6 :
			level = 'D';
			break;
		case 5 :
		case 4 :
		case 3 :
		case 2 :
		case 1 :
		case 0 :
			level = 'E';
			break;
	}
	printf("该成绩匹配等级为:%c",level); 
	return 0;
 } 
