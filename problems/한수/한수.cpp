#include<stdio.h>

int main()
{
	int input,hun,ten,one,count;
	count=0;
	scanf("%d",&input);
	if(input<=99)
	{
		printf("%d",input);
	}
	else 
	{
		while(input>=100)
		{
			hun=input/100;  //�����ڸ�   
			ten=(input%100)/10;  //�����ڸ�   
			one=((input%100)%10);  //�����ڸ�   
			if(hun-ten==ten-one)
			{
				count++;
			}
			input--;
		}
		printf("%d",count+99);  //100������ ���� ��� �ش�   
	}
}
