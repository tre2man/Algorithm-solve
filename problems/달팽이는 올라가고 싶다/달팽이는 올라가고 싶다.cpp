#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d %d %d",&a,&b,&c);
	d=a-b;
	if((c-a)%d==0)
	{
		printf("%d",(c-a)/d+1);
	} 
	else
	{
		printf("%d",(c-a)/d+2);
	}
}
