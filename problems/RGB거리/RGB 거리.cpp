#include <stdio.h>

int house[1001][3];  //0Àºr 1Àºg 2´Âb  
int ans[1001];

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

int mmin(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c) return a;
		else return c;
	}
	else
	{
		if(b<c) return b;
		else return c;
	}
}

int main()
{
	int num,i,j,k;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d %d %d",&house[i][0],&house[i][1],&house[i][2]);
	}
	
	ans[0]=mmin(house[0][0],house[0][1],house[0][2]);
	j=ans[0];
	
	for(k=1;k<=num;k++)
	{
		if(house[k-1][0]==house[k-1][1]||house[k-1][1]==house[k-1][2]||house[k-1][0]==house[k-1][2])
		{
			ans[k]=ans[k-1]+mmin(house[k][0],house[k][1],house[k][2]);
			j=mmin(house[k][0],house[k][1],house[k][2]);
		}
		else
		{
			if(j==house[k-1][0])
			{
				ans[k]=ans[k-1]+min(house[k][1],house[k][2]);	
				j=min(house[k][1],house[k][2]);
			}
			else if(j==house[k-1][1])
			{
				ans[k]=ans[k-1]+min(house[k][0],house[k][2]);	
				j=min(house[k][0],house[k][2]);
			}
			else
			{
				ans[k]=ans[k-1]+min(house[k][0],house[k][1]);
				j=min(house[k][0],house[k][1]);
			}
		}
		
	}
	printf("%d",ans[k-1]);
 } 
