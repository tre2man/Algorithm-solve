#include <stdio.h> //min 과 max 사이의 소수 구하기   

int main()
{
	int min,max;
	scanf("%d %d",&min,&max);
	for(;min<=max;min++)
	{
		for(int j=2;j<=min;j++)
		{
			if(j==min)
			{
				printf("%d\n",j);
			}
			else if(min%j==0)
			{
				break;
			}
		}
	}
}
