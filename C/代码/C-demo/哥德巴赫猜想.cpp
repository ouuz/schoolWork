#include <stdio.h>
#include <math.h>
int judgePrime (int n);
int main ()
{
	int i, k, n;
	int count=1;
	printf("%4d =%4d + %4d      ",4,2,2);
	for(n=6;n<=2000;n++)
	{
		k=(int)sqrt(n);
		for(i=3;i<=k;i++)
		{
			if(judgePrime(i)&&judgePrime(n-i))
			{
				printf("%4d =%4d + %4d      ",n,i,n-i);
				count++;
				if(count%4==0)
				{
					printf("\n");
				}
			}
		}
	}
	return 0;
 } 
 int judgePrime (int n)
 {
 	int i,k,judge=1;
 	if(n==1)
 	judge=0;
 	k=(int)sqrt(n);
 	for(i=2;i<=k;i++)
 	{
 		if(n%i==0)
 		judge=0;
	 }
	 return judge;
 }
