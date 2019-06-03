#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3 
int judgeSymmetry(int a[][N]);
int main ()
{
	int array[N][N];
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	switch(judgeSymmetry(array))
	{
		case 1:
			printf("¶Ô³Æ");
			break;
		case 0:
			printf("²»¶Ô³Æ");
	}
	return 0;
}
int judgeSymmetry(int a[][N])
{
	int judge=1;
	int i ,j ;
	for(i=0;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i][j]!=a[j][i])
			{
			   judge=0;
			   break;
	        }	
		}
	}
	return judge;
}
