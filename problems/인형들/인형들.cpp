#include <stdio.h>
#include <math.h>

int main()
{
	long double n,k,arr[501],ans,bs=0;
	scanf("%Lf %Lf",&n,&k);
	printf("%Lf %Lf",n,k);
	for(int i=0;i<(int)n;i++) 
	{
		scanf("%Lf",&arr[i]);
	}
	
	for(int i=0;i<n-k+1;i++)
	{
		bs=0; long double m=0;
		for(int j=i;j<i+k;j++) m+=arr[j];
		m/=k;
		for(int j=i;j<i+k;j++) bs+=pow(arr[j]-m,2);
		bs/=k;
		bs=sqrt(bs);
		if(i==0) ans=bs;
		if(ans>bs) ans=bs;
	}	
	printf("%.8f",ans);
 } 
