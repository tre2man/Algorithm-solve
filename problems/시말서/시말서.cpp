#include<stdio.h>

int main()
{
	int x,y,k,array[3];
	scanf("%d %d %d",&array[0],&array[1],&array[2]);
	for(x=0;x<2;x++)
	{
		for(y=0;y<2;y++)
		{
			if(array[y]<array[y+1])
			{
				k=array[y];
				array[y]=array[y+1];
				array[y+1]=k;
			}
		}
	}
	printf("%d",array[1]);
	return 0;
}
