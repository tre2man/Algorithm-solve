#include <stdio.h>  //ø¿¿œ∑Ø  
#include <math.h>

int main()
{
	double pi=0;
	double i;
	int k=1;
	
	while(k<1000000)
	{
		i=(double)k*k;
		pi+=1/i;
		k++;
	 } 
	 
	printf("%.15f",sqrt(6*pi));
}
