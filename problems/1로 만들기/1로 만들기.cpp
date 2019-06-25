#include <stdio.h>

int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int dp(int a)
{
	int arr[1000001]={0};
	if(a==1)
	{
		return arr[0];
	}
	
	for(int i=2;i<=a;i++)
	{
		arr[i]=arr[i-1]+1;
		if(i%2==0)
		{
			arr[i]=min(arr[i],arr[i/2]+1);
		}
		if(i%3==0)
		{
			arr[i]=min(arr[i],arr[i/3]+1);
		}
	}
	
	return arr[a];
}

int main()
{
	int a,b;
	scanf("%d",&a);
	printf("%d",dp(a));
}
