#include <stdio.h>
#define N  20
int main ()
{
	int sum=0, count=0;
	int array[N];
	int Max, min;
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&array[i]);
	}
	
	Max=array[0];
	for(i=1;i<N;i++)
	{
		if(array[i]>Max)
		Max=array[i];
	}
	
	min=array[0];
	for(i=1;i<N;i++)
	{
		if(array[i]<min)
		min=array[i];
	}
	
	for(i=0;i<N;i++)
	{
		if(array[i]!=Max && array[i]!=min)
		{
			sum+=array[i];
			count ++;
		}
	}
	printf("最大值是：%d\n",Max);
	printf("最小值是：%d\n",min);
	printf("平均值是：%f",float(sum/count));
	return 0;
}
