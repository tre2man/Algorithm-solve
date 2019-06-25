#include <stdio.h>

int arr[100]={0};

int pp(int a,int b)
{
	int i;
	arr[0]=a;
	if(a==b)
		return 1;
	
	for(i=1;i<=b;i++)
	{
		arr[i]=arr[i-1]*(a-i)/(i+1);
		//printf("%d\n",arr[i]);
	}
	return arr[i-2];
}


int main()
{
	int num,Left,Right,temp;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&Left,&Right);
		if(Left<Right)
		{
			temp=Right;
			Right=Left;
			Left=temp;
		}
		printf("%d\n",pp(Left,Right));
	 } 
}
