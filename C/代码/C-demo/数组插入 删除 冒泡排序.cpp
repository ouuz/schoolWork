#include <stdio.h>
#define SIZE 10
#void print (int a[], int n);
#void BubbleSort (int a[], int n);
#void insert (int a[], int n, int x);
#int delArray (int a[],int n, int x);
int main ()
{
	int n,array[SIZE];
	int i, j, x,y;
	do{
		printf("请输入十以内的正整数");
		scanf("%d",&n);
	}while(n<=0&&n>SIZE);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	print(array,n);
	printf("冒泡排序法后");
	BubbleSort(array,n);
	printf("请输入你要插入的数：");
	scanf("%d",&x);
	insert(array,n,x);
	print(array,n+1); 
	printf("请输入你要删除的数：");
	scanf("%d",&y);
	print(array,n);
	delArray(array,n);
	print(array,n-1);
	return 0;
 } 
 
void print (int a[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");
}
 
void BubbleSort (int a[], int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
}

void insert (int a[], int n, int x)
{
	int i,j;
	for(i=0;i<n&&a[i]<x;i++)
	for(j=n-1;j>=i;j--)
	a[j+1]=a[j];
	a[i]=x;
}
int delArray (int a[],int n, int x)
{
	int i,j;
	int flag=1;
	for(i=0;i<n&&a[i]!=x;i++);
	if(i==n)
	flag=0;
	else
	{
		for(j=n-1;j>=i;j--)
		{
			a[j]=a[j+1]; 
		}
	}
	return flag;
}
