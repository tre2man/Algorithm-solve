#include <stdio.h>

int n=0,white=0,blue=0;
int arr[129][129]={0}; //방문했으면 1로 저장 

void cut(int x,int y,int n)
{
	int color,z=1;
	//색 판별, 색이 같은 지 판별 
	
	if(arr[x][y]==1) color=1; //blue 
	else color=0; //white
	
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]!=color) z=0;
		}
	}
	if(z==1) //한 칸에 있는 종이의 색이 모두 같을경우 
	{
		if(color==1) blue++;
		else white++;
	}
	else //한 칸에 있는 종이의 색이 하나라도 다를경우 
	{
		cut(x,y,n/2);
		cut(x,y+n/2,n/2);
		cut(x+n/2,y,n/2);
		cut(x+n/2,y+n/2,n/2);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	
	cut(0,0,n); 
	printf("%d\n%d",white,blue);
}
