#include <stdio.h>

int main()
{
	bool arr[1000001]={1,1}; //0은 소수 1은 소수 아님 
	for(int i=2;i<=1001;i++) if(arr[i]==0) for(int j=2;j*i<=1000000;j++) arr[i*j]=1;
	//소수 판별 배열 저장 
	
	int num,k=2;
	
	while(1) 
	{
		scanf("%d",&num);
		if(num==0) return 0;
		while(num>k) //k를 증가 시키면서 소수인지 확인 
		{
			if(arr[k]==0&&arr[num-k]==0) break; //둘다 소수이고 조건 만족하면 탈출 
			k++;
		}
		printf("%d = %d + %d\n",num,k,num-k);
		k=2;
	}
} 
