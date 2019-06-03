#include <stdio.h>
#include <math.h> 
int judgeprime (int n);
//int count;
int main()
{
	int i,count=0;
	for(i=2;i<=100;i++)
	{
		if(judgeprime(i))
		{
			printf("%d",i);
			count++;
		}
	}
//	printf("¸öÊıÎª£º%d",count);
	return 0; 
}
int judgeprime (int n)
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
	printf("count=%d\n",count);
	return judge;
}
