#include <stdio.h>

int main(void)
{
    int input,threek,answer;
    threek=0;
    scanf("%d",&input);
    while(input!=0&&input!=1)
    {
    	if(input%5==0)
    	{
    		answer=(input/5+threek);
    		input=0;
		}
		else
		{
			input-=3;
			threek++;
			if(input==0)
			{
				answer=threek;
			}
		}
	}
	
    if(input==1)
	{
		printf("-1");
	}
	else
	{
		printf("%d",answer);
	}
}
