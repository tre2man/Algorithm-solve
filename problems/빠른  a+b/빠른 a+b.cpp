#include <stdio.h>

int main()
{
	int num,a,b,temp;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}
}
