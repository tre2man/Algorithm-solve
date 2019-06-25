#include <stdio.h>

int main()
{
	int stick,temp=0;
	scanf("%d",&stick);
	while(stick!=0)
	{
		if(stick%2!=0)
			temp++;
		stick=stick/2;
	}
	printf("%d",temp);
 } 
