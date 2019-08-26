#include <stdio.h>

int mi[110][110];
int visit[110][110];
int q[100000][2]={0};
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int n,m,front=0,rear=1,x,y;

void reset()
{
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			mi[j][i]=0;
			visit[j][i]=0;
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%1d",&mi[j][i]);
		}
	}
		
	q[0][0]=1,q[0][1]=1;
	
	while(front<rear)
	{
		x=q[front][0];
		y=q[front][1];
		front++;
		for(int k=0;k<4;k++)
		{
			if(mi[x+dx[k]][y+dy[k]]==1&visit[x+dx[k]][y+dy[k]]==0) //만약 그 좌표가 1이라면 (길이 통한다면) 
			{
				visit[x+dx[k]][y+dy[k]]=visit[x][y]+1;
				q[rear][0]=x+dx[k];
				q[rear][1]=y+dy[k];
				rear++;
			}
		}
	}
	
	printf("%d",visit[m][n]+1);
 } 
