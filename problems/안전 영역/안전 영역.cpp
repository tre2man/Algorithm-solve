#include <stdio.h>

int max=0,safenum=1;
int width=0;
int arr[101][101]={0};
int visit[101][101]={0};

int dfs(int x,int y,int water,int size)
{
	if(visit[x][y]==0&&visit[x][y]!=safenum-1) visit[x][y]=safenum;

	if(arr[x-1][y]>water&&visit[x-1][y]==0) dfs(x-1,y,water,size);
	if(arr[x][y+1]>water&&visit[x][y+1]==0) dfs(x,y+1,water,size);
	if(arr[x+1][y]>water&&visit[x+1][y]==0) dfs(x+1,y,water,size);
	if(arr[x][y-1]>water&&visit[x][y-1]==0) dfs(x,y-1,water,size);
}

void reset(int a)
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			visit[j][i]=0;
		}
	}
}

void print(int a)
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			printf("%d",visit[j][i]);
		}
		printf("\n");
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	reset(a);
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			scanf(" %d",&arr[j][i]);
			if(width<arr[j][i]) width=arr[j][i];
		}
	}
	
	int water=1;
	
	while(water<=width)
	{
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<a;j++)
			{
				dfs(j,i,water,a);
				safenum++;
			}
		}
		
		water++; safenum=1;
		print(a);
		reset(a);	
	}
	
	printf("%d %d",max,width);
	
}
