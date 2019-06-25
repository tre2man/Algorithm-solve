#include <stdio.h>
#include <stdlib.h>

int tomato[1000][1000];
int visit[1000][1000];

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int m,n,ans,check=1,end=0;
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&tomato[i][j]);
			//if(tomato[i][j]==1)
			//	visit[i][j]=1;
		}
	}
	
	while(check<1000)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(tomato[i][j]==check)
				{
					if(tomato[i-1][j]!=-1&&i-1>=0&&visit[i-1][j]!=1&&tomato[i-1][j]!=check)
					{
						tomato[i-1][j]=check+1;
						visit[i][j]=1;
						end++;
					}
					if(tomato[i+1][j]!=-1&&i+1>=0&&visit[i+1][j]!=1&&tomato[i+1][j]!=check)
					{
						tomato[i+1][j]=check+1;
						visit[i][j]=1;
						end++;
					}
					if(tomato[i][j-1]!=-1&&j-1>=0&&visit[i][j-1]!=1&&tomato[i][j-1]!=check)
					{
						tomato[i][j-1]=check+1;
						visit[i][j]=1;
						end++;
					}
					if(tomato[i][j+1]!=-1&&j+1>=0&&visit[i][j+1]!=1&&tomato[i][j+1]!=check)
					{
						tomato[i][j+1]=check+1;
						visit[i][j]=1;
						end++;
					}
					printf("%d\n",end);
				}
			}
		}
		
		if(end==0)
		{
			printf("-1");
			return 0;
		}
		
		check++;
		end=0;
	}

	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",tomato[i][j]);
		}
		printf("\n");
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			ans=max(max(tomato[i][j],tomato[i][j+1]),ans);
		}
	}
	
	printf("%d",ans-1);
}

