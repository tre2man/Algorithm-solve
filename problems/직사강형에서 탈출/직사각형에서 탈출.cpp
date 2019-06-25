#include <stdio.h>
#include <stdlib.h> 

int min(int a,int b)  //최소값 리턴   
{
	if(a<b)
		return a;
	else
		return b;
}

struct point  //구조체 선언  
{
	int x;
	int y;
};

int main()
{
	struct point dot;
	int Mx,My;
	scanf("%d %d %d %d",&dot.x,&dot.y,&Mx,&My);
	printf("%d",min(min(Mx-dot.x,My-dot.y),min(dot.x,dot.y))); 
	//직사각형좌표-한수위치 하고 한수위치 중 가장 작은 것을 출력 xy좌표 상관없이  
}
