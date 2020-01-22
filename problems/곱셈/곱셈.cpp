#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d %d",&a,&b);
	c=a;d=b;
	while(b!=0)
	{
		printf("%d\n",a*(b%10));
		b/=10;
	}
	printf("%d",c*d);
}
