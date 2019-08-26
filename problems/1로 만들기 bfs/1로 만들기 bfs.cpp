#include <stdio.h>

int visit[1000001]={0};
int q[2000000]={0};
int a,front=0,rear=1,ans=1,x;

int bfs()
{	
	q[front]=a;
	visit[a]=1;
	
	while(visit[1]==0)
	{
		x=q[front];
		front++;
		if(x%3==0&&visit[x/3]==0)
		{
			visit[x/3]=visit[x]+1;
			q[rear]=x/3;
			rear++;
		}
		
		if(x%2==0&&visit[x/2]==0)
		{
			visit[x/2]=visit[x]+1;
			q[rear]=x/2;
			rear++;
		}
		
		if(visit[x-1]==0)
		{
			visit[x-1]=visit[x]+1;
			q[rear]=x-1;
			rear++;
		}
	}
}

int main()
{
	scanf("%d",&a);
	
	bfs();
	
	printf("%d",visit[1]-1);
}
