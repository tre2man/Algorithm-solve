#include <stdio.h>
#include <math.h>

int main()
{
	int num,un,on,i,dd;
	
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d %d",&un,&on);
		un=un%10;
		
		if(un==4||un==9)
		{
			on=on%2;
			if(on==0)
			{
				on=2;
			}
		}
		else if(un==2||un==3||un==7||un==8)
		{
			on=on%4;
			if(on==0)
			{
				on=4;
			}
		}
		else
		{
		}
		
		if(un==1||un==5||un==6)
		{
			printf("%d\n",un);
		}
		else if(un==4||un==9)
		{
			
			dd=pow(un,on);
			printf("%d\n",dd%10);
		}
		else if(un==0)
		{
			printf("10\n");
		}
		else 
		{
			
			dd=pow(un,on);
			printf("%d\n",dd%10);
		}
	}
}
