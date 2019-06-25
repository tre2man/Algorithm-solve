#include<stdio.h>

int main()
{
	int i,count;
	count=0;
	char array[101];
	fgets(array,sizeof(array),stdin); //문자열 입력  
	while(array[count]!=NULL)
	{
		count++;
	}
	printf("%c",array[i]);
	for(i=1;i<count;i++)
	{
		if(i%10==0)  //10이 될 때마다 내려쓰기  
		{
			printf("\n");
		}
			printf("%c",array[i]);
	}
	return 0;
}
