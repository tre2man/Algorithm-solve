#include <stdio.h>
#include <stdlib.h> 

int min(int a,int b)  //�ּҰ� ����   
{
	if(a<b)
		return a;
	else
		return b;
}

struct point  //����ü ����  
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
	//���簢����ǥ-�Ѽ���ġ �ϰ� �Ѽ���ġ �� ���� ���� ���� ��� xy��ǥ �������  
}
