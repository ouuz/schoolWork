#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 40
int main ()
{
	char a[N];
	static  int b[26];
	int count = 0;
	int i, t;
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		t=rand()%26;    /* ·¶Î§£º[a,b] rand%(b-a+1)+a*/
		a[i]=t+'a';
		b[t]++;
	}
	for(i=0;i<26;i++)
	{
		printf ("%c-%2d\t",i+'a',b[i]);
	}
	return 0;
}
