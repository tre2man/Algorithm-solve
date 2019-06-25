#include <stdio.h>  //합병 정렬 예제  

int merge(int arr[],int left,int mid,int right)
{
	int sorted[right+1];
	int i,j,k,l;
	
	i=left;
	j=mid+1;
	k=left;
	
	while(i<=mid&&j<=right)  //분할 정렬된 리스트의 합병 
	{
		if(arr[i]<=arr[j])
			sorted[k++]=arr[i++];
		else
			sorted[k++]=arr[j++];
	}
	
	if(i>mid)   //남아있는 값들 일괄 복사  
	{
		for(l=j;l<=right;l++)
		{
			sorted[k++]=arr[l]; 				
		} 
	}
	else   //남아있는 값을 일괄 복사  
	{
		for(l=i;l<=mid;l++)
			sorted[k++]=arr[l];
	}
	
	for(l=left;l<=right;l++)  //sorted의 임시 배열을 arr로 복사 
		{
		arr[l]=sorted[l];
	}
	
}
int merge_sort(int arr[],int left,int right)  //합병 정렬  
{
	int mid;
	
	if(left<right)
	{
		mid=(left+right)/2;  //중간 위치 정해주기  
		merge_sort(arr,left,mid);  //앞쪽 리스트 정렬(분할) 
		merge_sort(arr,mid+1,right);  //뒤쪽 리스트 정렬(분할) 
		merge(arr,left,mid,right);  //분할한 두개 배열을 하나로 병합 
	}
}  

int main()
{
	int i,num;
	scanf("%d",&num);
	int arr[num];
	for(i=0;i<num;i++)  //배열 입력 받기        
	{
		scanf("%d",&arr[i]);
	}
	
	merge_sort(arr,0,num-1);  //합병 정렬 함수 실행          
	
	for(i=0;i<num;i++)   //출력하기      
	{
		printf("%d\n",arr[i]);
	}
}
