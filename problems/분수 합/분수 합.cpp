#include <stdio.h>  /* ��Ŭ���� ȣ���� �˰��� ���*/  


int arr[1000001];

int lcm(int a,int b) //�ּҰ����  
{
	int k,j=0;
	arr[0]=a; arr[1]=b;
	if(arr[0]<arr[1])   //�� ���ʿ� �� ū �� �Է�   
	{
		k=arr[1]; arr[1]=arr[0]; arr[0]=k;
	}
	while(1)  //���������� ���鼭 ������ �Է�  
	{
		arr[j+2]=arr[j]%arr[j+1]; 
		if(arr[j+2]==0)
		{
			break;
		}
		j++; 
	}
	return arr[0]*(arr[1]/arr[j+1]);
}

int gcd(int a,int b) //�ִ�����  
{
	int k,j=0;
	arr[0]=a; arr[1]=b;
	if(arr[0]<arr[1])   //�� ���ʿ� �� ū �� �Է�   
	{
		k=arr[1]; arr[1]=arr[0]; arr[0]=k;
	}
	while(1)  //���������� ���鼭 ������ �Է�  
	{
		arr[j+2]=arr[j]%arr[j+1]; 
		if(arr[j+2]==0)
		{
			break;
		}
		j++; 
	}
	return arr[j+1];
}


int main()
{	
	int num,a,b,c,d,e,f;
	scanf("%d %d",&a,&b); e=gcd(a,b);
	a=a/e; b=b/e;
	scanf("%d %d",&c,&d); f=gcd(c,d);
	c=c/f; d=d/f;
	e=a*(lcm(b,d)/b)+c*((lcm(b,d)/d)); f=lcm(b,d);
	printf("%d %d",e/(gcd(e,f)),f/(gcd(e,f)));
}
