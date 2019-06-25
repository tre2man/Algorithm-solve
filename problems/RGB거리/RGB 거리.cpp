#include <stdio.h>
#include <algorithm>

//int dp(int *bk,int *bbk,)

using namespace std;

int main()
{
	int num,i,temp;
	int arr[1010][3];
	int ans[1010];
	
	
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	
	ans[0]=min(min(arr[1][0],arr[1][1]),arr[1][2]);
	
	
	
}
