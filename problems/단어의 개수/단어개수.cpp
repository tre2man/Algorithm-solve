#include<stdio.h>

int main()
{
	int count,i=0;
	char array[1000001];
	
	fgets(array,sizeof(array),stdin);
		
	if(array[0]==' ')
	{
		count=0;
	}
	else
	{
		count=1;
	}
	
	while(array[i])
	{
		if(array[i]>='A'&&array[i]<='z'&&array[i-1]==' ')
		{
			count++;
		}
		i++;
	}
	
	printf("%d",count);
}



