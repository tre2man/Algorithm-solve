#include <stdio.h>

int a[15];

int dp(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 4;
	if(a[n]!=0)
	{
		return a[n];
	}
	return a[n]=dp(n-1)+dp(n-2)+dp(n-3);
}


int main()
{
	int num,j;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&j);
		printf("%d\n",dp(j));
	}
}
