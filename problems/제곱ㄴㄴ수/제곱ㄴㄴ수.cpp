#include <stdio.h>

int main()
{
	int arr[1000000];
	int MIN,MAX,NUM=0;
	int i;
	scanf("%d %d",&MIN,&MAX);
	for(i=1;i<=MAX/2+1;i++)
	{
		arr[i*i]=1;
	}
	
	for(i=1;i<=MAX;i++)
	{
		if(arr[i]==0)
			NUM++;
			printf("%d\n",i);
	}
	
	printf("%d",NUM);
	return 0;
}
