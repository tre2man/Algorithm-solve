#include <stdio.h>

int main()
{
	int arr[10001]={1,1}; //0�� �Ҽ� 1�� �Ҽ� �ƴ� 
	for(int i=2;i<=100;i++) if(arr[i]==0) for(int j=2;j*i<=10000;j++) arr[i*j]=1;
	//�Ҽ� �Ǻ� �迭 ���� 
	
	int a,num,k=2;
	
	scanf("%d",&a);
	for(int i=0;i<a;i++) 
	{
		scanf("%d",&num);
		while(num>k) //k�� ���� ��Ű�鼭 �Ҽ����� Ȯ�� 
		{
			if(arr[k]==0&&arr[num-k]==0&&2*k-num>=0) break; //�Ѵ� �Ҽ��̰� ���� �����ϸ� Ż�� 
			k++;
		}
		printf("%d %d\n",num-k,k);
		k=2;
	}
} 
