#include <stdio.h>

int pivo(int num)
{
	if(num==1||num==2)
	{
		return 1;
	}
	else
	{
		return pivo(num-2)+pivo(num-1);
	}
}

int main() 
{
	int num;
	scanf("%d",&num);
	printf("%d",pivo(num));
}
