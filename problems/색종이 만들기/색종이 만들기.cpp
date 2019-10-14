#include <stdio.h>

int n=0,white=0,blue=0;
int arr[129][129]={0}; //�湮������ 1�� ���� 

void cut(int x,int y,int n)
{
	int color,z=1;
	//�� �Ǻ�, ���� ���� �� �Ǻ� 
	
	if(arr[x][y]==1) color=1; //blue 
	else color=0; //white
	
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]!=color) z=0;
		}
	}
	if(z==1) //�� ĭ�� �ִ� ������ ���� ��� ������� 
	{
		if(color==1) blue++;
		else white++;
	}
	else //�� ĭ�� �ִ� ������ ���� �ϳ��� �ٸ���� 
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
