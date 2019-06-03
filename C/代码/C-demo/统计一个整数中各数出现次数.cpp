#include <stdio.h>
#define N 10
int main ()
{
	int digit[N]={0};
	int i,num;
	scanf("%d",&num);
	while(num)
	{
		i = num % N;
		digit[i]++;
		num = num / N;
	}
	for(i=0;i<N;i++)
	    printf("%d\t",i);
	    printf("\n");
	for(i=0;i<N;i++)
        printf("%d\t",digit[i]);
    return 0;
}
