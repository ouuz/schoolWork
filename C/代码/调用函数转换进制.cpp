#include <stdio.h>
void multibase (int n, int B);
int main()
{
	int n, B;
	printf("请输入要转换的十进制数和转换进制：\n");
	do
	{
		scanf("%d%d",&n,&B);
	}while(n<=0||B>16||B<2);
	multibase(n,B);
	return 0;
}
void multibase (int n, int B)
{
	int m;
	if(n)
	{
		multibase(n/B,B);
		m=n%B;
		if(m<10)
		{
			printf("%d",m);
		}
		else
		{
			printf("%c",m+55);
		}
	}
}
