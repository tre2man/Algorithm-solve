#include <stdio.h>

int arr[27][27]={0};
int visit[27][27]={0};
int dangenum[10000]={0};
int dnum=0;

void dfs(int x,int y,int size)  //dfs 탐색 시작 및 방문한곳 기록  
{
	visit[x][y]=dnum;
	if(arr[x][y]==1) dangenum[dnum]++;

	if(arr[x-1][y]==1&&visit[x-1][y]==0) dfs(x-1,y,size);
	if(arr[x][y+1]==1&&visit[x][y+1]==0) dfs(x,y+1,size);
	if(arr[x+1][y]==1&&visit[x+1][y]==0) dfs(x+1,y,size);
	if(arr[x][y-1]==1&&visit[x][y-1]==0) dfs(x,y-1,size);
}

void run(int size)
{
	for(int i=0;i<size;i++)  //방문하지않고 1이 있는경우 탐색 실행  
	{
		for(int j=0;j<size;j++)
		{
			if(arr[i][j]==1&&visit[i][j]==0) 
			{
				dnum++;
				dfs(i,j,size);
			}
		}
	}
}

void sort(int size) //정렬  
{
	int temp;
	for(int i=1;i<size;i++)
	{
		for(int j=1;j<size;j++)
		{
			if(dangenum[j]>dangenum[j+1])
			{
				temp=dangenum[j+1];
				dangenum[j+1]=dangenum[j];
				dangenum[j]=temp;
			}
		}
	}
}

int main()
{
	int size,i,j;
	scanf("%d",&size);
	
	for(i=0;i<size;i++)  //입력  
	{
		for(j=0;j<size;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	
	run(size);
	sort(dnum);
	
	printf("%d\n",dnum);
	
	for(int i=1;i<10000;i++)
	{
		if(dangenum[i]!=0) printf("%d\n",dangenum[i]);
		else break;
	}
 } 
