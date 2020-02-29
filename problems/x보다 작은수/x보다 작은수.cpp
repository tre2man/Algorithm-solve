#include<stdio.h>

int main()
{
	int arr[10000];
	int input,num,i,j,k;
	scanf("%d %d",&num,&input);
	for(i=0;i<num;i++) scanf("%d",&arr[i]);

	for(i=0;i<num;i++) if(arr[i]<input) printf("%d ",arr[i]);
	
	return 0;
}
