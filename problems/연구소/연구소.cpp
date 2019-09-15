#include <stdio.h>

int arr[10][10]={0};
int visit[10][10]={0};
int zero[100][2]={0}; 
int q[200]={0};
int front=0,rear=0,x,y,a,b,c=0,m,n,count=0;

void print()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}

void reset()
{
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			visit[i][j]=arr[i][j]=0;
		}
	}
}

void dfs(int x,int y)
{
	visit[x][y]=1;
	count++;
	
	if(arr[x+1][y]==0&&visit[x+1][y]==0) dfs(x+1,y);
	if(arr[x-1][y]==0&&visit[x-1][y]==0) dfs(x-1,y);
	if(arr[x][y+1]==0&&visit[x][y+1]==0) dfs(x,y+1);
	if(arr[x][y-1]==0&&visit[x][y-1]==0) dfs(x,y-1);
}

void check()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==2&&visit[i][j]==0)
			{
				dfs(i,j);
			}
		}
	}
}

int main()
{
	scanf("%d %d",&m,&n);
	reset();
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%1d",&arr[i][j]);
			if(arr[i][j]==0)
			{
				zero[c][0]=i;
				zero[c][1]=j;
				c++;
			}
		}
	}
	
	//check();
	dfs(1,1);
	print();
	
}
