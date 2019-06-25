#include <stdio.h>

int FX(int inum) //분해합을 구하는 함수  
{
	int sum,arr[7]={0,},divide=1000000; 
	
	sum=inum;
	
	for(int i=0;i<7;i++)
	{
		arr[i]=inum/divide;  //배열의 맨 왼쪽부터 숫자 나열  
		inum=inum%divide;
		divide=divide/10;
	}
	
	for(int i=0;i<7;i++)
	{
		sum+=arr[i];  //본인을 뺀 분해합 구하기  
	}
	
	return sum;
}

int main()
{
	int input,bf;  //bf 1부터 input까지 분해합 구할 인자 
	scanf("%d",&input);
	for(bf=2;bf<input;bf++)
	{
		if(FX(bf)==input)
		{
			printf("%d",bf);
			break;
		}
	}
	
	if(bf==input||input==1)
	{
		printf("0"); // 생성자가 없을 시에는?? 0출력  
	}
}
