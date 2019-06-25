#include <stdio.h>

int arr[301];
int ans[301];

int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int dp(int num)
{
	ans[1]=arr[1];
	ans[2]=arr[1]+arr[2];
	
	for(int i=3;i<=num;i++)
	{
		ans[i]=max(arr[i]+ans[i-2],arr[i-1]+arr[i]+ans[i-3]);
	}
	
	return ans[num];
}

int main()
{
	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("%d",dp(num));
	
 } 
