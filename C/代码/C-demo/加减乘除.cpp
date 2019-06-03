#include <stdio.h>
int main()
{
	int a,b,i,sum,difference,product;
	double quotient,ave;
	scanf("%d%d",&a,&b);
	sum=a+b;
	product=a*b;
	quotient=a*1.0/b;
	difference=a-b;
	ave=(a*1.0+b*1.0)/2;
	printf("它们的和是：%d\n",sum);
	printf("它们的差是：%d\n",difference);
	printf("它们的积是：%d\n",product);
	printf("它们的商是：%f\n",quotient);
	printf("它们的平均值是：%f\n",ave);
	return 0;
}
