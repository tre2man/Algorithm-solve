#include<stdio.h>

int main()
{
	int A,B,i,j;
	int arr[2];
	
	scanf("%d %d",&A,&B);
	
	j=100;
	for(i=0;i<3;i++)
	{
		arr[i]=A/j;
		A=A%j;
		j=j/10;
	}
	
	j=100;
	A=0;
	
	for(i=2;i>-1;i--)
	{
		A=A+arr[i]*j;
		j=j/10; 
	}
	
	
	j=100;
	for(i=0;i<3;i++)
	{
		arr[i]=B/j;
		B=B%j;
		j=j/10;
	}
	
	j=100;
	B=0;
	
	for(i=2;i>-1;i--)
	{
		B=B+arr[i]*j;
		j=j/10; 
	}
	
	
	if(A<B)
	{
		printf("%d",B);
	}
	else
	{
		printf("%d",A);
	}
}
