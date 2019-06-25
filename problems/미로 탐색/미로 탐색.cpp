#include <stdio.h>

int arr[101][101];
int visit[101][101];

int bfs(int arr[][],int N,int M)
{
	int x=0,y=0,count=1;
	visit[0][0]=1;
	while(x==N&&y==M)
	{
		for(;;)
		{
			
		}
	}
	return count;
}

int main()
{
	int N,M,i,j;
	
	scanf("%d %d",&N,&M);
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	
	bfs(arr,N,M);
}
