#include <stdio.h>
#include <math.h>

void space(int c)
{
	if(c==2)
		{
			printf("2\n");
			goto exit;
		}
	
		if(sqrt(c)-(int)sqrt(c)==0.0)
		{
			printf("%d\n",(int)sqrt(c)*2-1);
		}
	
		else if(sqrt(c)-(int)sqrt(c)>0.5)
		{
			printf("%d\n",(((int)sqrt(c)+1)*2)-1);
		}

		else
		{
			printf("%d\n",((int)sqrt(c))*2);
		}
		
		exit: ;
}

int main()
{
	int a,b,c,num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&a,&b);
		space(b-a);
	}
}
