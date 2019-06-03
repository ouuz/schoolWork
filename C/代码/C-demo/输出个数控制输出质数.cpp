#include <stdio.h>
#include <math.h>
int main ()
{
	int i,n,k,count=0;
	for(n=100;n<=999;n++)
	{
		k=(int)sqrt(n);
		for(i=2;i<=k;i++)
		{
			if(n%i==0)
			{
				break;
			}
		}
		if(i>k)
		{
			printf("%d  ",n);
			count++;
			if(count%8==0)
			{
				printf("\n");
			}
		}
	}
	return 0;
}
