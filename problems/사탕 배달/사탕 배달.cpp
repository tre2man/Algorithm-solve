#include <stdio.h>

int arr[2][250001]={0};
int five;
int ans;

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

void sort(int start,int end)
{
	int temp;
	for(int i=start;i<end;i++)
	{
		for(int j=start;j<end-1;j++)
		{
			if(arr[1][j]>arr[1][j+1])
			{
				temp=arr[1][j];
				arr[1][j]=arr[1][j+1];
				arr[1][j+1]=temp;
			}
		}
	}
}

void print(int end)
{
	for(int i=0;i<end;i++)
	{
		printf("%d %d",arr[0][i],arr[1][i]);
		printf("\n");
	}
}

int main()
{
	int n,w,i;
	scanf("%d %d",&n,&w);
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[0][i],&arr[1][i]);
		if(arr[0][i]==5&&arr[0][i-1]==3) five=i;
	}
	 
	sort(0,five);
	sort(five,i);
	
	print(n);
}
