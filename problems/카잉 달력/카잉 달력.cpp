#include <stdio.h>

int gcd(int m,int n)
{
	if(n%m==0) return m;
	return gcd(n%m,m);
}

int cal(int m,int n,int x,int y)
{
	int i,k=m/gcd(m,n)*n; //최소공배수 
	for(int i=x;i<=k;i+=m) 
	{
		if(y==(i-1)%n+1) return i;
	} 
	return -1;
}

int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int m,n,x,y;
		scanf("%d %d %d %d",&m,&n,&x,&y);
		printf("%d\n",cal(m,n,x,y));
	}
}
