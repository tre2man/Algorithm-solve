#include <stdio.h>

int arr[10001];

int self(int num)
{
	int a,b,c,d;
	a=num/1000;
	b=(num-1000*a)/100;
	c=(num%100)/10;
	d=num%10;
	return num+a+b+c+d;
}

int main()
{
	int temp;
	for(int i=1;i<=10000;i++)
	{
		temp=i;
		while(temp<10000)
		{
			if(arr[i]==0)
			{
				arr[self(temp)]=1;
			}
			temp=self(temp);
		}
	}
	
	for(int i=1;i<=10000;i++)
	{
		if(arr[i]==0)
		{
			printf("%d\n",i);
		}
	}
 } 
