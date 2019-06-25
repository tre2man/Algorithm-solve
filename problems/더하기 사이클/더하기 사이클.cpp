#include <stdio.h>

int main()
{
	int input,temp,count=1;
	scanf("%d",&input);
	temp=input; //입력받음  
	while(temp!=(input/10+input%10)%10+(input%10)*10)
	{
		input=(input/10+input%10)%10+(input%10)*10; //문제 조건에 부합하게 만든다  
		count++;  //카운트+1  
	}
	printf("%d",count);
}
