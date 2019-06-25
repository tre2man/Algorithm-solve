#include <stdio.h>

int main()
{
	int num,i,temp=2;
	scanf("%d",&num);
	i=num;
	if(num==1)
	{
		return 0;
	}
	while(i+1!=temp)
	{
		while(num%temp==0)
		{
			printf("%d\n",temp);
			num/=temp;
		}
		temp++;
	}
	return 0; 
}
