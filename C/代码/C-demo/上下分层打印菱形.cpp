#include <stdio.h>
int main()
{
	int i,k,j, m, n, r;
	for(i=1;i<=4;i++)
	{
		for(k=1;k<=4-i;k++)
		{
			printf(" ");
		}
		for(j=1;j<=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(m=3;m>=1;m--)
	{
		for(n=1;n<=4-m;n++)
		{
			printf(" ");
		}
		for(r=1;r<=2*m-1;r++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
