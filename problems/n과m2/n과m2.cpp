#include <stdio.h>

int n,m; //1���� n���� �ߺ����� m�� �� ��
int arr[9]={0};  //
bool visit[9]={0};  //�湮�� �� üũ 

//�׷��� Ž���� �̿��Ͽ� Ǯ��  

void dfs(int a,int b) 
{ 	
	if(a==m)
	{
		for(int i=0;i<m;i++) printf("%d ",arr[i]+1);
		printf("\n");
	}
	
	{
		for(int i=b;i<n;i++)
		{
			if(!visit[i])
			{
				visit[i]=1;
				arr[a]=i;
				dfs(a+1,i+1);
				visit[i]=0;
			}
		}
	} 
}

int main()
{
	scanf("%d %d",&n,&m);
	dfs(0,0); //���� ��� 
}
