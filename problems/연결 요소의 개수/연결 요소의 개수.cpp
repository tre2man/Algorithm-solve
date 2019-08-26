#include <stdio.h>

//간선의 최대는 50만  

int visit[1010]={0};
int graph[1010][1010]={0};
int chk=0;
int m,n,a,b;
int front=0,rear=0;
int num=1,ans=0;

int dfs(int check)
{
	visit[check]=1;
	
	for(int i=1;i<=n;i++)
	{
		if(graph[check][i]==1&&visit[i]==0)
		{
			dfs(i);
		}
	}	
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		graph[a][b]=1;
		graph[b][a]=1;
	}
	
	if(m==0) printf("%d",n);
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(visit[i]==0) ans++;
			dfs(i);
		}
	
		printf("%d",ans);
	}
 } 
