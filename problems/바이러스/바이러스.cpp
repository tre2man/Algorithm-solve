#include <stdio.h>

int com[101][101]={0};
int visit[101]={0}; 
int viruscom=0;

void dfs(int start,int net)
{
	int i;
	
	visit[start]=1;
	viruscom++;

	for(i=1;i<=net;i++)
	{
		if(com[start][i]==1 && visit[i]==0)
		{
			dfs(i,net);
		}
	}
}

int main()
{
	int num,net,x,y;
	scanf("%d",&num);
	scanf("%d",&net);
	for(int i=0;i<net;i++)
	{
		scanf("%d %d",&x,&y);
		com[x][y]=1;
		com[y][x]=1;
	}
	
	dfs(1,num);
	printf("%d",viruscom-1);
}
