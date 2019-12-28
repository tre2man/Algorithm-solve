#include <stdio.h>

int main()
{
	int arr[10001]={1,1}; //0은 소수 1은 소수 아님 
	for(int i=2;i<=100;i++) if(arr[i]==0) for(int j=2;j*i<=10000;j++) arr[i*j]=1;
	//소수 판별 배열 저장 
	
	int a,num,k=2;
	
	scanf("%d",&a);
	for(int i=0;i<a;i++) 
	{
		scanf("%d",&num);
		while(num>k) //k를 증가 시키면서 소수인지 확인 
		{
			if(arr[k]==0&&arr[num-k]==0&&2*k-num>=0) break; //둘다 소수이고 조건 만족하면 탈출 
			k++;
		}
		printf("%d %d\n",num-k,k);
		k=2;
	}
} 
