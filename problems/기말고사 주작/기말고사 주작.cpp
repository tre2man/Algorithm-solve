#include <stdio.h> 

//double ���� �Է��� lf�� ����� xf�� 

int main()
{
	int i;
	double sum,num,max;
	double array[1001];
	max=0; sum=0;
	
	scanf("%lf",&num);
	
	for(i=0;i<num;i++)
	{
		scanf("%lf",&array[i]);
		if(array[i]>max)
		{
			max=array[i];
		}
	}
	
	for(i=0;i<num;i++) sum=sum+(array[i]*100)/max;
	
	printf("%.3f\n",sum/num);
	
}
