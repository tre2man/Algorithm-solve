#include <stdio.h>

int n,m; //1���� n���� �ߺ����� m�� �� ��
int arr[9]={0};  //

//�׷��� Ž���� �̿��Ͽ� Ǯ��  
//�ߺ�, ���� ���� ���� 

void dfs(int a,int b) //a��°�� b�� ���� 
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
	scanf("%d %d",&n,&m); //n���߿� m�� �ߺ����� ���������� 
	for(int i=1;i<=n;i++) dfs(1,i);
}
