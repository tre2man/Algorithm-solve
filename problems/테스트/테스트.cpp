#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",(a*6916+b*4845+c*4200-1)%7980+1);
 } 

