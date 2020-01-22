#include <stdio.h>
#include <math.h>

int count=0;
int n,r,c;

int cut(int x,int y,int z)
{
	if(z==2)
	{
		
	}
	else
	{
		z/=2;
		cut(x,y,z);
		cut(x,y+z,z);
		cut(x+z,y,z);
		cut(x+z,y+z,z);
	}
}

int main()
{
	scanf("%d %d %d",&n,&r,&c);
	
	cut(0,0,(int)pow(2,n));
}
