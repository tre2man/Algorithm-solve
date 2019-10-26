#include <stdio.h>

int n,m; //1부터 n까지 중복없이 m개 고른 것
int arr[9]={0};  
int visit[9]={0};

//그래프 탐색을 이용하여 풀이  

void dfs(int a)
{ 
	printf("%d start\n",a);
	if(a==m)
	{
		for(int i=0;i<m;i++) printf("%d ",arr[i]);
		printf("\n");
	}
	
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			arr[a]=i;
			dfs(a+1);
			visit[i]=0;
		}
	}
	printf("%d end\n",a);
}

int main()
{
	scanf("%d %d",&n,&m);
	dfs(0);
}
