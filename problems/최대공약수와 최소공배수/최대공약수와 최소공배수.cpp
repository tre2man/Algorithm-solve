#include <stdio.h>  /* 유클리드 호제법 알고리즘 사용*/  

int main()
{
	int num,k,j=0; 
	int arr[100000];	
	

	scanf("%d %d",&arr[0],&arr[1]);
	if(arr[0]<arr[1])   //맨 왼쪽에 더 큰 수 입력   
	{
		k=arr[1]; arr[1]=arr[0]; arr[0]=k;
	}
	while(1)  //오른쪽으로 가면서 나머지 입력  
	{
		arr[j+2]=arr[j]%arr[j+1]; 
		if(arr[j+2]==0) break;
		j++; 
	}
	printf("%d\n%d",arr[j+1],arr[0]*(arr[1]/arr[j+1]));	 
}
