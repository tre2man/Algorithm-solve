#include <stdio.h>  /* ��Ŭ���� ȣ���� �˰��� ���*/  

int main()
{
	int num,k,j=0; 
	int arr[100000];	
	

	scanf("%d %d",&arr[0],&arr[1]);
	if(arr[0]<arr[1])   //�� ���ʿ� �� ū �� �Է�   
	{
		k=arr[1]; arr[1]=arr[0]; arr[0]=k;
	}
	while(1)  //���������� ���鼭 ������ �Է�  
	{
		arr[j+2]=arr[j]%arr[j+1]; 
		if(arr[j+2]==0) break;
		j++; 
	}
	printf("%d\n%d",arr[j+1],arr[0]*(arr[1]/arr[j+1]));	 
}
