#include<stdio.h>

int main()
{
	int i,count;
	count=0;
	char array[101];
	fgets(array,sizeof(array),stdin); //���ڿ� �Է�  
	while(array[count]!=NULL) count++;

	printf("%c",array[i]);
	for(i=1;i<count;i++)
	{
		if(i%10==0) printf("\n"); //10�� �� ������ ��������  
		printf("%c",array[i]);
	}
	return 0;
}
