#include <stdio.h>   //���ӽ� �׷���  

int main()
{
	double pi=0;
	int k=0;
	
	while(k<100)
	{
		++k;
		if(k%2!=0) pi+=4.0/(2.0*k-1.0);
		else pi-=4.0/(2.0*k-1.0);
	}
	
	printf("%.15f\n",pi); 
 } 
