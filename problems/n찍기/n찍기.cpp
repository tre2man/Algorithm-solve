#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d",&a);
	for(b=1;b<=a;b++)
	{
		for(c=0;c<b-1;c++) printf(" ");
		for(c=a;c>=b;c--) printf("*");
		printf("\n");
	}
}
