#include <stdio.h>  //0과 1이 몇 번 호출되는지 출력  

int main()
{
	int arr[45];
	int num,pp,temp;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		arr[0]=1; arr[1]=1; temp=1;
		scanf("%d",&pp);
		if(pp==0)
		{
			printf("1 0\n");
		}
		else if(pp==1)
		{
			printf("0 1\n");
		}
		else if(pp==2)
		{
			printf("1 1\n");
		}
		else
		{
			while(temp!=pp-1)
			{
				arr[temp+1]=arr[temp-1]+arr[temp];
				temp++;
			}
			printf("%d %d\n",arr[temp-1],arr[temp]);
		}
	}
	return 0;
}
