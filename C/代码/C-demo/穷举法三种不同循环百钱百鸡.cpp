//穷举法 百钱百鸡 
//确定变量个数 => 确定变量范围 => 确定变量实现条件 
#include <stdio.h>
void printTripleloop (int a, int b,int c);
void printDoubleloop (int a, int b,int c);
void printAcycle (int a, int b,int c);
int main ()
{	int a,b,c;
	printTripleloop (a, b, c);
	printf("\n");
	
	printDoubleloop (a, b, c);
	printf("\n");

	printAcycle (a, b, c);
	printf("\n");

	return 0;
}
void printTripleloop (int a, int b,int c)
{
	for(a=0;a<=20;a++)
	{
		for(b=0;b<=33;b++)
		{
			for(c=0;c<=100;c++)
			{
				if( a+b+c==100 && 15*a+9*b+c==300 )
				{
					printf("%d,%d,%d\n",a,b,c);
				}
			}
		}
	}
}


void printDoubleloop (int a, int b,int c)
{
	for(a=0;a<=20;a++)
	{
		for(b=0;b<=33;b++)
		{
			c=100-a-b;
			if( a+b+c==100 && 15*a+9*b+c==300 )
			{
				printf("%d,%d,%d\n",a,b,c);
			}
		}
	}
}

//用a来表示b c，且此时a的范围改变，由b表达式可求a最大值 
void printAcycle (int a, int b,int c)
{
	for(a=0;a<=14;a++)
	{
		b=(100-7*a)/4;
		c=(3*a+300)/4;
		if( a+b+c==100 && 15*a+9*b+c==300 )
			{
				printf("%d,%d,%d\n",a,b,c);
			}
	}
}


















