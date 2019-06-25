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
			hun=input/100;  //백의자리   
			ten=(input%100)/10;  //십의자리   
			one=((input%100)%10);  //일의자리   
			if(hun-ten==ten-one)
			{
				count++;
			}
			input--;
		}
		printf("%d",count+99);  //100이하의 수는 모두 해당   
	}
}
