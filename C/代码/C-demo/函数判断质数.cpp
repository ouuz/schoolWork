#include <stdio.h>
#include <math.h>
int judgePrime (int n);
int main ()
{
	int n;
	do{
		scanf("%d",&n);
		
	}while (n <= 0);
	switch(judgePrime(n))
	{
		case 1: printf("%d是质数",n);
		break;
		case 0:
			printf("%d不是质数",n);
	}
	return 0;
 } 
int judgePrime (int n)
{
	int i,k,result=1;
	if(n==1)
	{
		result=0;
	}
	k=(int)sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
		{
		result=0;
		}
	}
	return result;
}
