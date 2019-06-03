//floor函数结果相当于是去掉了小数点后面的数，即不大于该数的最小整数
//比如3.14，结果是double型的3
#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, i, k, j, m, n, r;
	printf("请输入你想打印的菱形的行数：");
	scanf("%d",&a); 
	b=a-1;
	for(i=1;i<=(floor(b/2)+1);i++)
	{
		for(k=1;k<=floor(b/2)-i+1;k++)
		{
			printf(" ");
		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(m=floor(b/2);m>=1;m--)
	{
		for(n=1;n<=(floor(b/2)-m+1);n++)
		{
			printf(" ");
		}
		for(r=1;r<=2*m-1;r++)
		{	printf("*"); }
		printf("\n");
	}
	return 0;
}
