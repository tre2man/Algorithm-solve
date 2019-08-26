#include <stdio.h>

int num,N,K,X,Y,W,D;
int build[1001];
int order[100001][100001];

int cal(int N,int K,int W,int D)
{
	
}

void reset()
{
	for(int i=0;i<100000;i++)
	{
		for(int j=0;j<100000;j++)
		{
			order[i][j]=0;
		}
	}
	
	for(int i=0;i<1000;i++) build[i]=0;
}

int main()
{
	scanf("%d",&num);
	
	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&N,&K);
		for(int j=0;j<N;j++) scanf("%d",&build[j]);
		for(int j=0;j<K;j++)
		{
			scanf("%d %d",&X,&Y);
			order[X][Y]=1;
		}
		scanf("%d",&W);
		
		cal(N,K,W,D);
	}
	
}
