#include <stdio.h>

long long arr[95]={1,1,};

long long Echinsu()
{
	for(int i=2;i<91;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
}

int main()
{
	int input;
	scanf("%lld",&input);
	Echinsu();
	printf("%lld",arr[input-1]);
}
