#include <stdio.h>  //dfs�� ���� bfs�� ť  


//dfs �� ���� ���� ���� �ڽ� ��带 ���������� �Է�  
//bfs �� �Ʒ� ���� ���� �ڽ� ��带 ���������� �Է�  

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
