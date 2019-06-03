#include <stdio.h>
#include <math.h>
int judgeprime (int n);
int main ()
{
	int m,count=0;
	for(m=100;m<=999;m++)
	{
		if(judgeprime(m))
		{
			printf("%6d",m);
			count++;
			if(count%5==0)
		{
			printf("\n");
		}
		}
	}
	return 0;
}
int judgeprime(int n)
{
	int i,k,judge=1;
	if(n==1)
	{
		judge=0;
	}
	k=(int)sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
		{
			judge=0;
		}
	}
	return judge;
}
