#include <stdio.h>
int main()
{
	double item, sum=0,a=2.0,b=1.0;
	int n, i=1, sign=1;
	scanf("%d", &n);
	do
	{
		item = sign*a/b;
		sum += item;
		sign = -sign;
		a=b+a;
		b=a-b;
		i ++; 
	}while(i<=n);
	printf("项数n的值为：%d\n", n); 
	printf("sum等于%f", sum);
	return 0;
}

