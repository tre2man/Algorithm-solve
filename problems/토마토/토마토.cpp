#include <stdio.h>

int tomato[1000][1000];
int visit[1000][1000];
int q[1000050][2],front=0,rear=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int x,y,m,n,k,i,j;

void reset()
{
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			tomato[i][j]=-1;
			visit[i][j]=0;
		}
	}
}

void print()
{
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",visit[i][j]);
		}
		printf("\n");
	}
}

void qprint()
{
	for(int i=0;q[i][0]!=0&&q[i][1]!=0;i++) 
		printf("%d %d\n",q[i][0],q[i][1]);
 } 

int main()
{
	scanf("%d %d",&m,&n);
	
	reset();
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %d",&tomato[i][j]);
			if(tomato[i][j]==1)
			{
				q[rear][0]=i; //큐에 1이 들어가있는 좌표를 순서대로 입력한다  
				q[rear][1]=j;
				rear++;
			}
		}
	}
	
	while(front<rear)
	{
		x=q[front][0]; //좌표를 x,y로 입력  
		y=q[front][1];
		front++;
		for(k=0;k<4;k++)
		{
			if(tomato[x+dx[k]][y+dy[k]]==0) //근처에 안 익은 것이 있으면 익게 한다. 4방위  
			{
				tomato[x+dx[k]][y+dy[k]]=1; //익게 한다  
				visit[x+dx[k]][y+dy[k]]=visit[x][y]+1; //전에 있던 것 보다 1 더 큰것으로. 언제 익었는지 저장  
				q[rear][0]=x+dx[k]; //이번에는 익은 것을 집어넣는다  
				q[rear][1]=y+dy[k];
				rear++;
			}
		}
	}
	
	
	int count=0,check=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(count<visit[i][j]) count=visit[i][j];
			if(tomato[i][j]==0) check=1;
		}
	}
	
	print();
	qprint();
	
	if(check==1) printf("-1");
	else printf("%d",count);
}
