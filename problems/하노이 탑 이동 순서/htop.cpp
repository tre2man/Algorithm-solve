/*
void hto(int n,char from,char tmp,char to)
{
	if(n==1) printf("원판 %d 를 %c 에서 %c 로 옮긴다.\n",n,from,to);
	else
	{
		hto(n-1,from,to,tmp);
		printf("원판 %d 를 %c 에서 %c 로 옮긴다.\n",n,from,to);
		hto(n-1,tmp,from,to);
	} 
}

int main()
{
	hto(3,'A','B','C'); 
} 
*/

#include <stdio.h>

void htop(int n,int from,int temp,int to)
{
	if(n==1) printf("%d %d\n",from,to);
	else
	{
		htop(n-1,from,to,temp);
		printf("%d %d\n",from,to);
		htop(n-1,temp,from,to);
	}
}

int main()
{
	int n;
	int arr[30]={0,1};
	
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		arr[i]=arr[i-1]*2+1;
	}
	
	printf("%d\n",arr[n]);
	
	htop(n,1,2,3);
 } 
