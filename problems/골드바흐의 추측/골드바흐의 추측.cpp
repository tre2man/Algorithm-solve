#include <stdio.h>

int main()
{
	bool arr[1000001]={1,1}; //0�� �Ҽ� 1�� �Ҽ� �ƴ� 
	for(int i=2;i<=1001;i++) if(arr[i]==0) for(int j=2;j*i<=1000000;j++) arr[i*j]=1;
	//�Ҽ� �Ǻ� �迭 ���� 
	
	int num,k=2;
	
	while(1) 
	{
		scanf("%d",&num);
		if(num==0) return 0;
		while(num>k) //k�� ���� ��Ű�鼭 �Ҽ����� Ȯ�� 
		{
			if(arr[k]==0&&arr[num-k]==0) break; //�Ѵ� �Ҽ��̰� ���� �����ϸ� Ż�� 
			k++;
		}
		printf("%d = %d + %d\n",num,k,num-k);
		k=2;
	}
} 
