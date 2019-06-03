#include <stdio.h>
#include <math.h>
int main()
{
	int n, i,k;
	do{
		scanf("%d",&n);
	}while(n<=0);
	if(n==1)
	{
		printf("不是质数");
	}
	else
	{
		k=(int)sqrt(n);
		for(i=2;i<=k;i++)
		if(n%i==0)
		{
			break;
		}
	}
	if(i>k)
	{
		printf("%d是质数",n);
	}
	else
	{
		printf("%d不是质数",n);
	}
	return 0;
 } 
