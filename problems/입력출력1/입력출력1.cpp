#include <stdio.h>

int main(void)
{
	char a[100];
	gets(a);
	char b[100];
	gets(b);
	char c[100];
	gets(c);
	
	printf("%s\n",a);
	printf("%s\n",b);
	printf("%s",c); 
	return 0;
}
