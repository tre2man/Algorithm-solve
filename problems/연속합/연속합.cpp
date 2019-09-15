#include <stdio.h>

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int n;
	int arr[100010]={0};
	int ans[100010]={0};
	int pout=0;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	
	for(int i=1;i<=n;i++) ans[i]=max(ans[i-1]+arr[i],arr[i]);
	
	pout=ans[1];
	
	for(int i=2;i<=n;i++) pout=max(pout,ans[i]);
	
	printf("%d",pout);
}
