#include <stdio.h>

int main()
{
	int input,temp,count=1;
	scanf("%d",&input);
	temp=input; //�Է¹���  
	while(temp!=(input/10+input%10)%10+(input%10)*10)
	{
		input=(input/10+input%10)%10+(input%10)*10; //���� ���ǿ� �����ϰ� �����  
		count++;  //ī��Ʈ+1  
	}
	printf("%d",count);
}
