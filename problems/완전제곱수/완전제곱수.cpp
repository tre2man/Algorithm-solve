#include<stdio.h>
#include<math.h>

int main()
{
	double i,count,sum,mmin;
	int min,max;
	count=0; sum=0;
	scanf("%d%d",&min,&max);
	
	for(i=min;i<max+1;i++)
	{
		if(min==pow((sqrt(min)),2))
		{
			count++;
			sum=sum+min;
		}
		if(count==1)
		{
			mmin=min;
		}
	}
	
	if(count==0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n%d",sum,mmin);
	}
}
