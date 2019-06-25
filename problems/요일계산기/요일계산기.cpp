#include <stdio.h>

int main()
{
	int month,day,a;
	scanf("%d %d",&month,&day);
	for(a=month-1;a>0;a--)
	{
		if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
		{
			day+=31;
		}
		else if(a==2)
		{
			day+=28;
		}
		else
		{
			day+=30;
		}
	}
	if(day%7==1)
	{
		printf("MON");
	}
	else if(day%7==2)
	{
		printf("TUE");
	}
	else if(day%7==3)
	{
		printf("WED");
	}
	else if(day%7==4)
	{
		printf("THU");
	}
	else if(day%7==5)
	{
		printf("FRI");
	}
	else if(day%7==6)
	{
		printf("SAT");
	}
	else
	{
		printf("SUN");
	}
}
