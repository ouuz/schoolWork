#include <stdio.h>
int digitSum(int n);
int main()
{
	int n,sum;
	scanf("%d",&n);
	do
	{
		printf("Errors!");
		scanf("%d",&n);
	}while (n<0);
	sum=digitSum(n);
	printf("组成这个数的数字之和是：%d",sum);
	return 0;
 } 
 int digitSum(int n)
 {
 	if(n<10)
 	return n;
 	else
 	return n%10 + digitSum(n/10);
 }
