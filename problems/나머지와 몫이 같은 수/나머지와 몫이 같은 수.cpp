#include <stdio.h>

long long dd(long long j)
{
	long long temp=0;
	for(long long i=1;i<=j;i++)
	{
		temp+=i;
	}
	return temp;
}

int main()
{
	long long input,temp=0;
	scanf("%lld",&input);
	printf("%lld",(input+1)*dd(input-1));
}
