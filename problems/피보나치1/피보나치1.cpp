#include <stdio.h>

int main() 
{
	int num,i,a,b,c;
	a=0; b=1; c=1
	;
	scanf("%d",&num);
	
	if(num==1||num==2)
	{
		printf("1");
	}
	else
	{ 
		for(i=1;i<num;i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		printf("%d",c);
	}
	
}
