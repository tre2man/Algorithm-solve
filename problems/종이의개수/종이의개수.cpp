#include <stdio.h>

char arr[2188][2188]={0}; 

int minus=0,zero=0,one=0; 

void cut(int x,int y,int n)
{
	bool check=1;
	int paper=arr[x][y];
	int k=n/3;
	
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(paper!=arr[i][j]) check=0;
		}
	}
	
	if(check) //모두같을경우 또는 1칸일경우 
	{
		if(paper==-1) minus++;
		else if(paper==0) zero++;
		else one++;
	}
	
	else
	{
		cut(x,y,k);
		cut(x,y+k,k);
		cut(x,y+2*k,k);
		cut(x+k,y,k);
		cut(x+k,y+k,k);
		cut(x+k,y+2*k,k);
		cut(x+2*k,y,k);
		cut(x+2*k,y+k,k);
		cut(x+2*k,y+2*k,k);
	} 
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	
	cut(0,0,n);
	printf("%d\n%d\n%d",minus,zero,one);
}
