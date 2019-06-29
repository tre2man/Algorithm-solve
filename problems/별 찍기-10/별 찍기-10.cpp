#include <stdio.h>

char arr[2188][2188]={NULL};

void squ(int n,int x,int y)
{
	int k;
	if(n==1) arr[x][y]='*';
	else
	{
		k=n/3;
		squ(k,x,y);          //1������  
		squ(k,x,y+k);         //2������
		squ(k,x,y+k*2);       //3������
		squ(k,x+k,y);         //4������
		squ(k,x+k,y+k*2);    //5������
		squ(k,x+k*2,y);       //6������
		squ(k,x+k*2,y+k);       //7������
		squ(k,x+k*2,y+k*2);     //8������
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	squ(n,1,1);

	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			if(arr[x][y]=='*') printf("%c",arr[x][y]);
			else printf(" ");
		}
		printf("\n");
	}
}
