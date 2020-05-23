#include <stdio.h>
#include <string.h>

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int N,K,ans=0;
	char start[]="anta";
	char end[]="tica";
	char input[20];
	int arr[100]={0};
	
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%s",&input);
		arr[i]=strlen(input)-8;
	}
	
	for(int i=0;i<N;i++)
	{
		int check=0,temp=0;
		for(int j=i;j<N;j++)
		{
			if(temp+arr[j]<=K)
			{
				temp+=arr[j];
				check++;
			}
			ans=max(ans,check);
		}
	}
	
	printf("%d",ans);
 } 
