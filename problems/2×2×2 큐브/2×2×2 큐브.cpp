#include <stdio.h>

int main()
{
	int temp,arr[24];
	for(int i=0;i<24;i++)
	{
		scanf("%d",&arr[i]);
	}
	if(arr[12]==arr[13]&&arr[12]==arr[14]&&arr[12]==arr[15]&&arr[16]==arr[17]&&arr[16]==arr[18]&&arr[16]==arr[19]&&(arr[0]==arr[5]&&arr[2]==arr[7]&&arr[4]==arr[9]&&arr[6]==arr[11]&&arr[8]==arr[20]&&arr[10]==arr[22]||arr[0]==arr[22]&&arr[2]==arr[20]&&arr[4]==arr[1]&&arr[6]==arr[3]&&arr[8]==arr[5]&&arr[10]==arr[7])) //1번경우  
	{
		printf("1");
	}
	else if(arr[0]==arr[1]&&arr[0]==arr[2]&&arr[0]==arr[3]&&arr[8]==arr[9]&&arr[8]==arr[10]&&arr[8]==arr[11]) //2번경우  
	{
		printf("1");
	}
	else if(arr[4]==arr[5]&&arr[4]==arr[6]&&arr[4]==arr[7]&&arr[20]==arr[21]&&arr[20]==arr[22]&&arr[20]==arr[23]) //3번째 경우  
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}



arr[0]==arr[5]&&arr[2]==arr[7]&&arr[4]==arr[9]&&arr[6]==arr[11]&&arr[8]==arr[20]&&arr[10]==arr[22]
arr[0]==arr[22]&&arr[2]==arr[20]&&arr[4]==arr[1]&&arr[6]==arr[3]&&arr[8]==arr[5]&&arr[10]==arr[7]
