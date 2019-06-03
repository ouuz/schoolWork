//计算给定的日期是该年的第几天
#include <stdio.h>
int main()
{
	int mon[]={0,31,0,31,30,31,30,31,31,30,31,30,31};
	int i, daycount,year,month,day;
	do
	{
		printf("请输入日期（2018-12-03）\n");
		scanf("%d-%d-%d",&year,&month,&day);
	}while(year<0||month<0||day<0||month>13||day>31);
	if(((year%400==0)&&(year%100==0))||((year%4==0)&&(year%100!=0)))
	{
		mon[2]=29;
	}
	else
	{
		mon[2]=28;
	}
	for(i=1;i<month;i++)
	{
		daycount=daycount+mon[i];
	}
	daycount=daycount+day;
	printf("%d",daycount);
}
