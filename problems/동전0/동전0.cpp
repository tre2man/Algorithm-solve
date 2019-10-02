#include <stdio.h>

int main()
{
	int arr[10];
	int n,k,temp=0,a,ans=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&arr[i]); //가치는 오름차순으로 주어짐. 
		if(arr[i]>k&&temp==0)
		{
			a=i-1;
			temp=1;
		}
	}
	
	while(n!=0)
	{
		if(n-arr[i])
	}
	
	
	printf("%d",a);
}
