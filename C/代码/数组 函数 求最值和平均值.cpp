#include <stdio.h>
#define N 10
void print (int a[],int n);
int maxnum(int a[],int n);
int minnum(int a[],int n);
double average(int a[],int n);
int main()
{
	int n,i;
	int array[N];
	int max, min;
	double ave;
	do
	{
		printf("请输入10以内的非零正整数：\n");
		scanf("%d",&n);
	}while(n<0||n>10);
	printf("请输入%d个数：\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	print(array,n);
	max=maxnum(array,n);
	min=minnum(array,n);
	ave=average(array,n);
	printf("最大值为：%d\n",max);s
	printf("最小值为：%d\n",min);
	printf("平均值为：%f\n",ave);
	return 0;
}
void print (int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
int maxnum(int a[],int n)
{
	int i,max;
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
int minnum(int a[],int n)
{
	int i,min;
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	return min;
}
double average(int a[],int n)
{
	int i,sum,count,min,max;
	double ave;
	for(i=0;i<n;i++)
	{
		if(a[i]!=max&&a[i]!=min)
		{
			sum=sum+a[i];
			count++;
		}
		if(count)
		{
			ave=sum*1.0/count;
		}
	}
	return ave;
}
