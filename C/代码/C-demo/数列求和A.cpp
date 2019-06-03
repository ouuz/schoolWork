#include <stdio.h>
#include <math.h> 
double Fact(int n);
int main ()
{
	double m, s=0, item=1;
	int n=1,sign=1;
	scanf("%lf",&m);
	do
	{
		item=pow(m,n)/Fact(n);
		s += item;
		sign= -sign;
		n++;
	}while(fabs(item)>=1E-4);
	printf("%.2f\n",s);
	return 0; 
}
double Fact(int n)
{
	if(!n)
	{
		return (1.0);
	}
	else
	{
		return (n*Fact(n-1));
	}
}
