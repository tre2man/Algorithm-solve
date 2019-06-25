#include<stdio.h>

int main()
{
	int i=0;
	char arr[102];
	fgets(arr,sizeof(arr),stdin);
	while(arr[i]!=NULL)
	{
		i++;
	}
	printf("%d",i-1);
}
