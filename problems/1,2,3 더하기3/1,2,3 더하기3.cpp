#include <stdio.h>

long long a[1000010];

long long dp(long long n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 4;
	if(a[n]!=0)
	{
		return a[n];
	}
	return a[n]=(dp(n-1)+dp(n-2)+dp(n-3))%1000000009;
}

int main()
{
	long long j;
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lld",&j);
		printf("%lld\n",dp(j));
	}
}
