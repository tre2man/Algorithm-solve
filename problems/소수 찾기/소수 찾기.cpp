#include <stdio.h>

int arr[1001]={1,1,};

int main()
{
	int temp,num,a,count=0;
	for(int i=2;i<=1000;i++)
	{
		temp=i;
		while(temp+i<=1000)
		{
			temp=temp+i;
			if(arr[temp]!=1)
			{
				arr[temp]=1;
			}
		}
	}
	
	scanf("%d",&num);
	
	for(int i=0;i<num;i++)
	{
		scanf("%d",&a);
		if(arr[a]==0)
		{
			count++;
		}
	}
	
	printf("%d",count);
}
