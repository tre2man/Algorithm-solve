#include<stdio.h>

int main()
{
	int num,i,a,b;
	int array[10000];
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		a=getchar();
		getchar();
		array[i]=a+(getchar()-48);
		getchar();
	}
	
	for(i=0;i<num;i++)
	{
		printf("%d\n",array[i]);
	}
}
