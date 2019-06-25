#include <stdio.h>  //그대로 출력하기2까지 적용됨  

int main()
{
	char arr[101];
	while(fgets(arr,101,stdin))  //fgets는 입력에 실패하면 \0을 출력한다 
	{								//또한 \n 만을 구분자로 사용한다  
		printf("%s",arr);
	}
	return 0;
 } 
