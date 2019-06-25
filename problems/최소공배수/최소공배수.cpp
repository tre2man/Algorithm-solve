#include <stdio.h>  /* 유클리드 호제법 알고리즘 사용*/  


int arr[1000001];

int lcm(int a,int b)
{
	int k,j=0;
	arr[0]=a; arr[1]=b;
	if(arr[0]<arr[1])   //맨 왼쪽에 더 큰 수 입력   
	{
		k=arr[1]; arr[1]=arr[0]; arr[0]=k;
	}
	while(1)  //오른쪽으로 가면서 나머지 입력  
	{
		arr[j+2]=arr[j]%arr[j+1]; 
		if(arr[j+2]==0)
		{
			break;
		}
		j++; 
	}
	return arr[0]*(arr[1]/arr[j+1]);
}


int main()
{	
	int num,a,b;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",lcm(a,b));
	}
	return 0; 
}
