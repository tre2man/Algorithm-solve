#include <stdio.h>

int FX(int inum) //�������� ���ϴ� �Լ�  
{
	int sum,arr[7]={0,},divide=1000000; 
	
	sum=inum;
	
	for(int i=0;i<7;i++)
	{
		arr[i]=inum/divide;  //�迭�� �� ���ʺ��� ���� ����  
		inum=inum%divide;
		divide=divide/10;
	}
	
	for(int i=0;i<7;i++)
	{
		sum+=arr[i];  //������ �� ������ ���ϱ�  
	}
	
	return sum;
}

int main()
{
	int input,bf;  //bf 1���� input���� ������ ���� ���� 
	scanf("%d",&input);
	for(bf=2;bf<input;bf++)
	{
		if(FX(bf)==input)
		{
			printf("%d",bf);
			break;
		}
	}
	
	if(bf==input||input==1)
	{
		printf("0"); // �����ڰ� ���� �ÿ���?? 0���  
	}
}
