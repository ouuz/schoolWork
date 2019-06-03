//硬核辗转相除法 被除数 除数 余数 三者轮换 前移 
#include <stdio.h>
int main ()
{
	int a, b, r;
	scanf("%d%d",&a,&b);
	do
	{
		r=a%b;
		a=b;
		b=r;
	} while(r!=0);
	printf("最大公约数是:%d",a);
	return 0;
}
