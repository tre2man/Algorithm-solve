#include <stdio.h>
//using namespace std;

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int arr[10010]={0},dp[10010]={0},num;
	scanf("%d",&num);
	for(int i=0;i<num;i++) scanf("%d",&arr[i]);	
	
	dp[0]=arr[0];
	dp[1]=arr[0]+arr[1];
	dp[2]=max(max(dp[1],dp[0]+arr[2]),arr[1]+arr[2]);
	
	for(int i=3;i<=num;i++)
	{
		dp[i]=max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]);
		dp[i]=max(dp[i-1],dp[i]);
	}
	
	printf("%d",dp[num]);
 } 
