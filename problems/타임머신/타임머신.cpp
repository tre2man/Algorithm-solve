#include <stdio.h>

int main()
{
	int num,temp,sum=0;
	int arr[1001]={0};
	scanf("%d",&num);
	
	for(int i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<num-1;i++)
	{
		for(int j=0;j<num-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	for(int i=num;i>0;i--)
	{
		sum+=arr[num-i]*i;
	}
	
	printf("%d",sum);
}
