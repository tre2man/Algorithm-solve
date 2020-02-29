#include <stdio.h>
#include <math.h>

int main()
{
	int i,num;
	double xa,ya,ra,xb,yb,rb,x;
	
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&ra,&xb,&yb,&rb); //원1 원2 정보  
		x=sqrt(pow(xa-xb,2)+pow(ya-yb,2));
		if(xa==xb&&ya==yb)  //두 원의 중심이 같을 때  
		{
			if(ra==rb) printf("-1\n");
			else printf("0\n");
		}
		else  //두 원의 중심이 다를 때  
		{
			if(ra+rb<x) printf("0\n");
			else if(x==ra+rb) printf("1\n");
			else if(abs(ra-rb)==x) printf("1\n");
			else if(abs(ra-rb)>x) printf("0\n");
			else printf("2\n");
		}
	}
}
