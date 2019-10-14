#include <stdio.h>

int arrA[51]={0},arrB[51]={0};

void sort(int num) //오름차순 
{
	int temp;
	for(int i=0;i<num-1;i++)
	{
		for(int j=0;j<num-1-i;j++)
		{
			if(arrA[j]>arrA[j+1])
			{
				temp=arrA[j+1];
				arrA[j+1]=arrA[j];
				arrA[j]=temp;	
			}
			if(arrB[j]<arrB[j+1])
			{
				temp=arrB[j+1];
				arrB[j+1]=arrB[j];
				arrB[j]=temp;	
			}
		}
	}
}

int main()
{
	int num,ans=0;
	scanf("%d",&num);
	
	for(int i=0;i<num;i++) scanf("%d",&arrA[i]);
	for(int i=0;i<num;i++) scanf("%d",&arrB[i]);
	
	sort(num);
	
	for(int i=0;i<num;i++) ans+=arrA[i]*arrB[i];
	
	printf("%d",ans);
	return 0;
}
