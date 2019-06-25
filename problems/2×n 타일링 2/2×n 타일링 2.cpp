#include <stdio.h>

int a[1001];

int tile(int n)
{
	if(n==1) return 1;
	if(n==2) return 3;
	if(a[n]!=0) return a[n];
	return a[n]=(tile(n-1)+(tile(n-2))*2)%10007;
 } 

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",tile(n));
}
