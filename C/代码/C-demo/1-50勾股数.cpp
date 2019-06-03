//类似穷举法 三层循环嵌套 变量xyz 变量范围都是1-50 实现条件 (x*x+y*y==z*z)&&(x<y)&&(y<z)
#include <stdio.h>
int main ()
{
	int x, y ,z;
	for(x=1;x<=50;x++)
	{
		for(y=1;y<=50;y++)
		{
			for(z=1;z<=50;z++)
			{
				if((x*x+y*y==z*z)&&(x<y)&&(y<z))
				{
					printf("%d %d %d\n",x,y,z);
				}
			}
		}
	}
	return 0;
 } 
