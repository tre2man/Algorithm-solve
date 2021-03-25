#if 0

#include <stdio.h>

int visit[1000001]={0};
int q[2000000]={0};
int a,front=0,rear=1,ans=1,x;

void bfs()
{
	int count=0;
	
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
		count++;
	}
}

int main()
{
	scanf("%d",&a);
	bfs();
	printf("%d",visit[1]-1);
}

#endif

#if 0

#include <iostream>
using namespace std;

int dp(int a)
{
	int arr[1000001]={0};
	if(a==1)
	{
		return arr[0];
	}
	
	for(int i=2;i<=a;i++)
	{
		arr[i]=arr[i-1]+1;
		if(i%2==0)
		{
			arr[i]=min(arr[i],arr[i/2]+1);
		}
		if(i%3==0)
		{
			arr[i]=min(arr[i],arr[i/3]+1);
		}
	}
	
	return arr[a];
}

int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",dp(a));
}

#endif