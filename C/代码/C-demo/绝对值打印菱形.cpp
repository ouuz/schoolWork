#include <stdio.h>
#include <math.h> 
int main()
{
	int i, j;
	for(i=1;i<=7;i++)
	{
		for(j=1;j<=fabs(4-i);j++)
		printf(" ");
		for(j=1;j<=7-2*fabs(4-i);j++)
		printf("*");
		printf("\n");
	}
	return 0;
}
