#include <stdio.h>  //dfs는 스택 bfs는 큐  


//dfs 맨 위에 값을 빼고 자식 노드를 위에서부터 입력  
//bfs 맨 아래 값을 빼고 자식 노드를 위에서부터 입력  

int DfsVisit[1001];
int BfsVisit[1001];
int arr[1001][1001];

int BFS()
{
	
}

int DFS()
{
	
}

int main()
{
	int a,b,x,y,start;
	scanf("%d %d %d",&a,&b,&start);
	for(int i=0;i<b;i++)
	{
		scanf("%d %d",&x,&y);
		arr[x][y]=1;
		arr[y][x]=1;
	}
	
	
}
