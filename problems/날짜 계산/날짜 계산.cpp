#include <stdio.h>

int main()
{
	int e,s,m,count=0;
	scanf("%d %d %d",&e,&s,&m);

	while(1)
	{
		if(count%15==e-1&&count%28==s-1&&count%19==m-1)
		{
			break;
		}
		count++;
	}
	printf("%d",count+1);
 } 
