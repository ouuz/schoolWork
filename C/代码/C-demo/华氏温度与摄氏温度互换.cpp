#include <stdio.h>
double Transformtemperature(double tem);
int main ()
{
	int tem,tratem;
	scanf("%lf",&tem);
	do
	{
		tratem = Transformtemperature ( tem );
		printf("tem = %f ; tratem = %f", tem, tratem);
		scanf("%lf", &tem);
	}while(tem >= 0);
	return 0;
}
double Transformtemperature(double tem)
{
	return tem*9/5+32;
}
