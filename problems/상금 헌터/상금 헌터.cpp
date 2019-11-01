#include <stdio.h>

int main()
{
	int n;
	int money[2][101]=
	{
		{500,300,200,50,30,10},
		{512,256,128,64,32,0}
	};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c=0,count=0;
		scanf("%d %d",&a,&b);
		if(a==0) a=100;
		if(b==0) b=100;
		for(int j=a;j>0;j-=++c)
		{
			count++;
		}
		c=1; int count1=1;
		for(int j=b-1;j>0;j-=c)
		{
			count1++;
			c*=2;
		}
		printf("%d\n",(money[0][count-1]+money[1][count1-1])*10000);


	}
 } 
