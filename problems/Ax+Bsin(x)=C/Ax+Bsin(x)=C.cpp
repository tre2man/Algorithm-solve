#include <stdio.h>
#include <math.h>

double ssin(double a,double b,double c)
{
	double x=1.0,k=1.0;
	int temp=0;
	
	while(x<=1000000)  //������ Ȯ���ϱ�  
	{
		if(a*x+b*sin(x)-c>0)
		{
			x-=1.0;
			break;
		}
		x+=1.0;
	}
	
	for(int i=0;i<=9;i++)  //�Ҽ��� Ȯ���ϱ�(0���� 9����) 
	{
		exit:
		if(temp==11) break;  //11��°���� Ȯ���ϸ� for�� ����  
		if(a*x+b*sin(x)>c)  //�Լ����� 0���� Ŭ ���  
		{
			x-=k/10.0;    //
			temp++; i=0;  //�ڸ��� �̵�  
			k/=10.0;      //-1�� �ڸ��� �Ҽ��� Ȯ���Ϸ� ����  
			goto exit;    //exit�� �̵�  
		}
		if(i==9)  // �Ҽ��� �κ��� ���� 9���?  
		{
			temp++; i=0;  //�ڸ��� �̵�  
			k/=10.0;      //-1�� �ڸ��� �Ҽ��� Ȯ���Ϸ� ����  
			goto exit;    //exit�� �̵�
		}
		x+=k/10.0;
	}
	
	return x;
}

int main()
{
	double a,b,c;
	
	scanf("%lf %lf %lf",&a,&b,&c);
	
	printf("%.10lf",ssin(a,b,c));
 } 
