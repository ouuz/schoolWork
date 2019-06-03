#include <stdio.h>
void printPart (int n);
int main()
{
	int n;
	printPart (n);
	return 0;
}

void printPart (int n)
{
	int i, j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d+%d=%d ",i,j,i+j);
		}
		printf("\n");
	}
}

