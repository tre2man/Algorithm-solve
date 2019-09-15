#include <stdio.h>

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int n,ans=1;
	scanf("%d",&n);
	int arr[n+10]={0};
	int dp[n+10]={0};
	
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

	
	
	printf("%d\n",ans);
}
