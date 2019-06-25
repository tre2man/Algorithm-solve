#include <stdio.h>

int main()
{
	int num,H,W,C,Front,Back;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d %d %d",&H,&W,&C);
		if(C%H==0)
		{
			Front=H;
			Back=C/H;
		}
		else
		{
			Front=C%H;
			Back=(C/H)+1;
		}
			
		if(Back<10)
			printf("%d0%d\n",Front,Back);
		else
			printf("%d%d\n",Front,Back);
	}
}
