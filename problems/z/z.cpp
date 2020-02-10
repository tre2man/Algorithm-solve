#include <stdio.h>
#include <math.h>

bool arr[32769][32769]={0};
int count=0,ans;


//Å½»ö ½ÃÀÛ ÁÂÆ÷ x,y Å½»ö Ä­ÀÇ Å©±â z 
void cut(int x,int y,int z)
{
	if(arr[x][y]==1)
	{
		printf("%d",count);
		return;
	}
	else
	{
		cut(x,y,z/2);
		cut(x,y+z/2,z/2);
		cut(x+z/2,y,z/2);
		cut(x+z/2,y+z/2,z/2);
	}
}

int main()
{
	int n,r,c;
	scanf("%d %d %d",&n,&r,&c);
	arr[r][c]=1;
	
	cut(0,0,(int)pow(2,n));
	printf("%d",ans);
}
