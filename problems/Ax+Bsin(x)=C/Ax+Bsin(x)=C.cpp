#include <stdio.h>
#include <math.h>

double ssin(double a,double b,double c)
{
	double x=1.0,k=1.0;
	int temp=0;
	
	while(x<=1000000)  //정수부 확인하기  
	{
		if(a*x+b*sin(x)-c>0)
		{
			x-=1.0;
			break;
		}
		x+=1.0;
	}
	
	for(int i=0;i<=9;i++)  //소수부 확인하기(0에서 9까지) 
	{
		exit:
		if(temp==11) break;  //11번째까지 확인하면 for문 종료  
		if(a*x+b*sin(x)>c)  //함수식이 0보다 클 경우  
		{
			x-=k/10.0;    //
			temp++; i=0;  //자릿수 이동  
			k/=10.0;      //-1승 자리의 소수점 확인하러 가기  
			goto exit;    //exit로 이동  
		}
		if(i==9)  // 소수점 부분이 만약 9라면?  
		{
			temp++; i=0;  //자릿수 이동  
			k/=10.0;      //-1승 자리의 소수점 확인하러 가기  
			goto exit;    //exit로 이동
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
