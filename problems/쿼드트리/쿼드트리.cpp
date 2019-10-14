#include <stdio.h>

int n=0,white=0,black=0;
int arr[65][65]={0}; //방문했으면 1로 저장 

void tree(int x,int y,int n)
{
	int color,z=1;
	//색 판별, 색이 같은 지 판별 
	
	if(arr[x][y]==1) color=1; //black
	else color=0; //white
	
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]!=color) z=0;
		}
	}
	if(z==1) //한 칸에 있는 픽셀의 색이 모두 같을경우 
	{
		if(color==1) printf("1");
		else printf("0");
	}
	else //한 칸에 있는 픽셀의 색이 하나라도 다를경우 
	{
		printf("(");
		tree(x,y,n/2);
		tree(x,y+n/2,n/2);
		tree(x+n/2,y,n/2);
		tree(x+n/2,y+n/2,n/2);
		printf(")");
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	
	tree(0,0,n); 
}
