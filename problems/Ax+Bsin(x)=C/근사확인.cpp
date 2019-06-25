#include <stdio.h>
#include <math.h>

int main()
{
	double i=161;
	printf("%lf\n",i+sin(i)-161);
	if(i+sin(i)-161>0) printf("1");
	else printf("0");
}
