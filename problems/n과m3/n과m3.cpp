#include <stdio.h>

int n,m; //1부터 n까지 중복없이 m개 고른 것
int arr[9]={0};  //

//그래프 탐색을 이용하여 풀이  
//중복, 같은 숫자 가능 

void dfs(int a,int b) //a번째에 b가 들어간다 
{ 
	arr[a]=b; 
	
	if(a==m) 
	{
		for(int i=1;i<=m;i++) printf("%d ",arr[i]);
		printf("\n");
	}
	else for(int i=1;i<=n;i++) dfs(a+1,i);
}

int main()
{
	scanf("%d %d",&n,&m); //n개중에 m개 중복가능 같은수가능 
	for(int i=1;i<=n;i++) dfs(1,i);
}
