#include<stdio.h>

int main()
{
	int a,b,c,cal,sum;
	int array[9];
	scanf("%d %d %d",&a,&b,&c);
	cal=a*b*c;
	b=100000000;
	
	for(a=0;a<10;a++)
	{
		array[a]=-1;
	}
	
	c=0;
	while(cal<b)
	{
		b=b/10;
		c++;
	}
	
	for(a=c;a<9;a++)
	{
		array[a]=cal/b;
		cal=cal%b;
		b=b/10;
	}
	
	a=0; b=0; c=0; sum=0;
	
	while(b<10)
	{
		for(c=0;c<9;c++)
		{
			if(array[c]==b)
			{
				sum++;
			}
		}
		b++;
		printf("%d\n",sum);
		sum=0;
	}	
}
