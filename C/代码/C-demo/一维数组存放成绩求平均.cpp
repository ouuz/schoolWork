#include <stdio.h>
#define N  3 
int main ()
{
	double array[N];
	int i,count=0;
	double sum=0;
	for(i=0;i<N;i++)
	{
		scanf("%lf",&array[i]);
		sum += array[i];
		count++;
	}
	printf("存放了%d个学生的成绩，平均分为%f",count,double(sum/count));
	return 0;
}
