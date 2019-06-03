#include <stdio.h>
#include <math.h>
#define Pi 3.14
double findVolume (int r,int h);
double findSurfacearea(int r,int h);
int main ()
{
	double r,h,V,sa;
	scanf("%lf %lf",&r,&h);
	if(r<=0||h<=0)
	{
	printf("Errors！");
	return 0;
}
	V=findVolume(r,h);
	sa=findSurfacearea(r,h);
	printf("半径是%f 高是%f的圆锥体的体积是%f，表面积是%f",r ,h , V, sa);
	return 0;
}
double findVolume (int r,int h)
{
	return Pi*pow(r,2)*h/3;
}
double findSurfacearea(int r,int h)
{
	double s;
	s=sqrt(r*r+h*h);
	return Pi*r*(r+s);
}
