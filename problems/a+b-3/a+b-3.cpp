#include <stdio.h>

int main()
{
	int num;
	char arr[4];
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		getchar();
		fgets(arr,sizeof(arr),stdin);
		
		printf("%d\n",arr[0]+arr[2]-96);
	}
	return 0;
}
