#include <stdio.h>
#include <string.h>
int main(){
	/*char a[12];
	a="dsdjsikjdsl";
	上面的是错的 因为这样是给数组名赋值*/
	
	char a[12]="dssfsdfsdf";
    puts(a); 
    
	char *b;
	b ="dssfsdfsdfsdfdsfsdfsdfsdfsdf";
	puts(b);
	
	char c[20];
	strcpy(c,"dfsfsdfsdfsdfsdhfghfghfghfghfghfg");
	puts(c);
	return 0;
} 
