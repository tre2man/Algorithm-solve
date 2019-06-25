#include<stdio.h>

int main()
{
	char arr[81];
	int num,i,j,sum,x;
	
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		arr[81]={0}; sum=0; x=0;
		scanf("%s",arr);
		for(j=0;arr[j]!='\0';j++)
		{
			if(arr[j]=='O')
			{
				x++;
				sum=sum+x;
			}
			else
			{
				x=0;
			}
		}
		printf("%d\n",sum);
	}
	
 } 
