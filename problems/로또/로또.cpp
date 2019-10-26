#include <stdio.h>

//독일 로또는 1~49의 수 중 6개를 고른다. 
//정해진 숫자에서 6개씩 뽑자
 
int arr[15];
int ans[6];
int n;

void dfs(int a,int b)
{
	if(b==6)
	{
		for(int i=0;i<6;i++) printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	
	for(int i=a;i<n;i++)
	{
		ans[b]=arr[i];
		dfs(i+1,b+1);
	}	 
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n!=0)
		{
			for(int i=0;i<n;i++) scanf("%d",&arr[i]);
			dfs(0,0);
			printf("\n");
		}
		else break;
		
		for(int i=0;i<14;i++) arr[i]=0;
	} 
}
