#include <stdio.h>

int arr[1005][1005]={0};
int visit[1005][1005]={0};
int q[1000050][2]={0};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int front,rear,x,y;

int main()
{
	int size,i,j;
	scanf("%d",&size);
	
	front=rear=0;
	
	for(i=0;i<size;i++)  //ют╥б  
	{
		for(j=0;j<size;j++)
		{
			scanf("%1d",&arr[i][j]);
			if(arr[i][j]==1)
			{
				q[rear][0]=i;
				q[rear][1]=j;
				rear++;
			}
		}
	}

	while(front<rear)
	{
		x=q[front][0];
		y=q[front][1];
		front++;
		
		for(int k=0;k<4;k++)
		{
			if(arr[x+dx[k]][y+dy[k]]==0)
			{
				arr[x+dx[k]][y+dy[k]]=1;
				visit[x+dx[k]][y+dy[k]]=visit[x][y]+1;
				q[rear][0]=x+dx[k];
				q[rear][1]=y+dy[k];
				r++;
			}
		}
	}
	
	
	
 } 
