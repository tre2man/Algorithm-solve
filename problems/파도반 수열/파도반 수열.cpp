#include <stdio.h>

long long arr[110]={0,1,1,1,2,2};

long long pado(long long n)
{
	if(n<6) return arr[n];
	else
	{
		for(int i=6;i<n+1;i++)
		{
			arr[i]=arr[i-1]+arr[i-5];	
		}
		
		return arr[n];
	}
}

int main()
{
	int num;
	long long input;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lld",&input);
		printf("%lld\n",pado(input));
	 } 
}
