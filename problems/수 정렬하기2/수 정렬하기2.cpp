#include <stdio.h>  //�պ� ���� ����  

int merge(int arr[],int left,int mid,int right)
{
	int sorted[right+1];
	int i,j,k,l;
	
	i=left;
	j=mid+1;
	k=left;
	
	while(i<=mid&&j<=right)  //���� ���ĵ� ����Ʈ�� �պ� 
	{
		if(arr[i]<=arr[j])
			sorted[k++]=arr[i++];
		else
			sorted[k++]=arr[j++];
	}
	
	if(i>mid)   //�����ִ� ���� �ϰ� ����  
	{
		for(l=j;l<=right;l++)
		{
			sorted[k++]=arr[l]; 				
		} 
	}
	else   //�����ִ� ���� �ϰ� ����  
	{
		for(l=i;l<=mid;l++)
			sorted[k++]=arr[l];
	}
	
	for(l=left;l<=right;l++)  //sorted�� �ӽ� �迭�� arr�� ���� 
		{
		arr[l]=sorted[l];
	}
	
}
int merge_sort(int arr[],int left,int right)  //�պ� ����  
{
	int mid;
	
	if(left<right)
	{
		mid=(left+right)/2;  //�߰� ��ġ �����ֱ�  
		merge_sort(arr,left,mid);  //���� ����Ʈ ����(����) 
		merge_sort(arr,mid+1,right);  //���� ����Ʈ ����(����) 
		merge(arr,left,mid,right);  //������ �ΰ� �迭�� �ϳ��� ���� 
	}
}  

int main()
{
	int i,num;
	scanf("%d",&num);
	int arr[num];
	for(i=0;i<num;i++)  //�迭 �Է� �ޱ�        
	{
		scanf("%d",&arr[i]);
	}
	
	merge_sort(arr,0,num-1);  //�պ� ���� �Լ� ����          
	
	for(i=0;i<num;i++)   //����ϱ�      
	{
		printf("%d\n",arr[i]);
	}
}
