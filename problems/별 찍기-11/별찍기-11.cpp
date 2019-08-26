#include <stdio.h>

char arr[3072][7000]={NULL};

void tri(int x,int y,int num)
{
	if(num==3)
	{
		arr[x][y+2]='*';
		arr[x+1][y+1]='*';
		arr[x+1][y+3]='*';
		arr[x+2][y]='*';
		arr[x+2][y+1]='*';
		arr[x+2][y+2]='*';
		arr[x+2][y+3]='*';
		arr[x+2][y+4]='*';
	}
	
	else
	{
		tri(x,y+num/2,num/2);   //위 
		tri(x+num/2,y,num/2);   //왼쪽  
		tri(x+num/2,y+num,num/2);    //오른쪽  
	}
 } 
 
void print(int x,int y)
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			if(arr[i][j]==NULL) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	tri(0,0,n);
	print(n,(n*5/3)+(n/3-1));
 } 
