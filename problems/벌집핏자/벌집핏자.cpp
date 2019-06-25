#include<stdio.h>

int main()
{
	int num,hex,i;
	hex=8;
	i=2;
	scanf("%d",&num);
	if(num==1)
	{
		printf("1");
	}
	else
	{
		while(1)
		{
			if(num<hex)
			{
				printf("%d",i);
				break;
			}
			else
			{
				hex=hex+(6*i);
				i++;
			}
		}
	}
	return 0;
	
}
