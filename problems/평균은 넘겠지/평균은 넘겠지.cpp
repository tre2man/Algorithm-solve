#include<stdio.h>
#include<math.h>

double ever(double score,double arr[])
{
	double sum=0,ans;
	for(int i=0;i<score;i++)
	{
		sum+=arr[i];
	}
	return sum/score;
}

int main()
{
	int cases;
	double arr[1010],num,high=0;
	scanf("%d",&cases);
	for(int i=0;i<cases;i++)
	{
		scanf("%lf",&num);
		for(int j=0;j<num;j++)
		{
			scanf("%lf",&arr[j]);
		}
		
		for(int j=0;j<num;j++)
		{
			if(arr[j]>ever(num,arr))
			{
				high+=1;
			}
		}
		printf("%.3f%%\n",high*100/num);
		arr[1010]={0,}; high=0;
	}
}
