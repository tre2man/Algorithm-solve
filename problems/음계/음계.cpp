#include <stdio.h>

int main()
{
	int arr[8],a=1,d=8;
	for(int i=0;i<8;i++) 
	{
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<7;i++)
	{
		if(arr[i]+1==arr[i+1])
		{
			a++;
		}
		else if(arr[i]-1==arr[i+1])
		{
			d--;
		}
	}
	
	if(a==8)
	{
		printf("ascending");
	}
	else if(d==1)
	{
		printf("descending");
	}
	else
	{
		printf("mixed");
	}
}
