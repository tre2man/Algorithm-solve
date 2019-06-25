#include <stdio.h>

int main()
{
	int i=30,temp=0,num,k;
	scanf("%d",&num);
	while(i>=0)
	{
		k=(num>>i)&1;
		if(k==1)
			temp=1;
		if(temp==1)
			printf("%d",k);
		i--;
	}
	
	return 0;
}
