#include <stdio.h>
#include <math.h>
#include max 1000000000

int arr[110][11]={0};

int main()
{
	int a,ans=0;
	scanf("%d",&a);
	
	arr[1][0]=0;
	for(int i=1;i<=9;i++)
		arr[1][i]=1;
		
	for(int i=2;i<=a;i++)
	{
		arr[i][0]=arr[i-1][1];
		arr[i][9]=arr[i-1][8];
		for(int j=1;j<=8;j++)
		{
			arr[i][j]=arr[i-1][j-1]%max+arr[i-1][j+1]%max;
			arr[i][j]%=max;	
		}
	}
	
	for(int i=0;i<=9;i++)
	{
		ans+=arr[a][i];
		ans%=max;
	}
		
	printf("%d",ans%max);
	
 } 
