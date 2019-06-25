#include <stdio.h>

int main()
{
	int array[10000],answer[10000];
	int count,x,y,z,sum,times,plus,a; 
	scanf("%d\n",&count);
	for(x=0;x<(count*2)-2;x=x+2)
	{
		scanf("%d %d\n",&array[x],&array[x+1]);
	}
	x=0;
	for(z=0;z<count*2;z+=2)
	{
		sum=1; times=1; plus=1; 
		a=array[z]+array[z+1]-1;
		while(a>sum)
		{
			sum+=plus;
			plus++;
			times++;
		}
		answer[x]=times+1;
		x++;
	}
	for(x=0;x<3;x++)
	{
		printf("%d\n",answer[x]);
	}
	printf("%d",array[0]);
	printf("%d",array[1]);
	printf("%d",array[2]);
	printf("%d",array[3]);
	printf("%d",array[4]);
	printf("%d",array[5]);
}
