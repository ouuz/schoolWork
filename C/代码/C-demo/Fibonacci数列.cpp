//主要是数列所指后移,f1表示Fn-2,f2表示Fn-1,fn表示当前数,有利用到交换原理 
#include <stdio.h>
int main ()
{
	int f1,f2,f3,n,i;
	scanf("%d",&n);
	f1=1;
	f2=1;
	printf("%d %d ",f1,f2);
	for(i=2;i<n;i++)
	{
		f3=f1+f2;
		printf("%d ",f3);
		f1=f2;
		f2=f3;
	
	}
	return 0;
 } 
