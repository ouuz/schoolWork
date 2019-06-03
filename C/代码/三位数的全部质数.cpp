#include<stdio.h>
#include<math.h>
int main()
{int n,i,count,k;
count=0;
k=(int)sqrt(n);
for(n=101;n<999;n++)
{ for(i=2;i<=k;i++)
    { if(n%i==0)
        break;
	}
  if(i>k&&(count+1)%5!=0)
      {printf("%6d",n);
	  count++;
	  continue;
	  }
  if(i>k&&(count+1)%5==0)
	  {printf("%6d\n",n);
	  count++;
	  }
}
return 0;
}
