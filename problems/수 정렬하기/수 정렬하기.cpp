#include <stdio.h>

int main()
{
	int input,i,j,change;
	int arr[1000];
	 
	scanf("%d",&input);
	for(i=0;i<input;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<input;i++)
	{
		for(j=0;j<input-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				change=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=change;
			}
		}
	}
	
	for(i=0;i<input;i++)
	{
		printf("%d\n",arr[i]);
	}
}
