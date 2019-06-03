#include <stdio.h>
int main()
{
    char a;
    char b,c,d;
    a=getchar();
    printf("The ASCII of 'X' is %d\n.",a); 
    getchar();
    b=a/100;
    c=a%100/10;
    d=a%100%10;
    putchar(b+'0');
    putchar(c+'0');
    putchar(d+'0');
    return 0;
}
