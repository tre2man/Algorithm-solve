#include <stdio.h>

int visit[110000]={0};
int q[210000]={0};
int front=0,rear=1,x=0,t=1;

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	
	if(b==0)
	{
		a++;b++;
	}

	q[0]=a; //첫번째 큐에 출발지점 입력  
	visit[a]=1;
	
	while(1)
	{
		x=q[front];  //x는 큐의 처음 입력값(좌표)입력  
		front++;
		if(x-1>0&&visit[x-1]==0)
		{
			visit[x-1]=visit[x]+1;
			q[rear]=x-1;
			rear++;
		}

		if(x<110000&&visit[x+1]==0)
		{
			visit[x+1]=visit[x]+1;
			q[rear]=x+1;
			rear++;
		}

		if(x*2<110000&&visit[x*2]==0)
		{
			visit[x*2]=visit[x]+1;
			q[rear]=x*2;
			rear++;
		}

		if(x==b) break;
	}
	
	printf("%d",visit[x]-1);
 } 
