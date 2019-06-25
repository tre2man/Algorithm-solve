#include <stdio.h>

int main()
{
	int  arr[100];
	int i,j,ONE,TWO,count;
	ONE=0; TWO=0; count=0;
	
	fgets(arr,sizeof(arr),stdin);
	printf("%d",sizeof(arr)); 
	
	j=1;
	for(i=sizeof(arr)-1;i>-1;i--)
	{
		if(count<2)
		{
			if(arr[i]==' ')
			{
				count++;
			}
			else
			{
				TWO=arr[i]*j;
				j=j*10;
			}
		}
		else
		{
			if(count==2)
			{
				j=1;
			}
			if(arr[i]==' ')
			{
				count++;
			}
			else
			{
				ONE=arr[i]*j;
				j=j*10;
			}
		}
	}
	

}
