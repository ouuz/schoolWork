//带参宏替换计算给定年份的二月天数
#include<stdio.h> 
#define DAYS_FEB(year) (year%400==0)||((year%4==0)&&(year%100!=0))
int main()
{
	int daysum,year;
	printf("Please enter the year you want to query:\n");
	do
	{
		scanf("%d",&year);
	 } while(year<0);
	switch(DAYS_FEB(year))
	{
		case 1:
			daysum=29;
			break;
		case 0:
			daysum=28;
	}
	printf("days of the FEB.: %d\n",daysum);
	return 0;
}
