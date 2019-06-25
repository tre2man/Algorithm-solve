#include <stdio.h>

int arr[9];

int sort(int arr[])
{
	int temp;
	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<9;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int main()
{
	
	int temp=0;
	
	for(int i=0;i<9;i++)
	{
		scanf("%d",&arr[i]);
		temp=temp+arr[i];
	} 
	temp=temp-100;
	
	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<9;j++)
		{
			if(arr[i]+arr[j]==temp)
			{
				arr[i]=0; arr[j]=0;
				goto exit;
			}
		}
	}
	
	exit:
	
	sort(arr);
	
	for(int i=0;i<9;i++)
	{
		if(arr[i]!=0)
			printf("%d\n",arr[i]);
	}
 } 
