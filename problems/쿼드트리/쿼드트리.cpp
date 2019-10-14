#include <stdio.h>

int n=0,white=0,black=0;
int arr[65][65]={0}; //�湮������ 1�� ���� 

void tree(int x,int y,int n)
{
	int color,z=1;
	//�� �Ǻ�, ���� ���� �� �Ǻ� 
	
	if(arr[x][y]==1) color=1; //black
	else color=0; //white
	
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]!=color) z=0;
		}
	}
	if(z==1) //�� ĭ�� �ִ� �ȼ��� ���� ��� ������� 
	{
		if(color==1) printf("1");
		else printf("0");
	}
	else //�� ĭ�� �ִ� �ȼ��� ���� �ϳ��� �ٸ���� 
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
