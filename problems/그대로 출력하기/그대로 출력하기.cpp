#include <stdio.h>  //�״�� ����ϱ�2���� �����  

int main()
{
	char arr[101];
	while(fgets(arr,101,stdin)) printf("%s",arr);  //fgets�� �Է¿� �����ϸ� \0�� ����Ѵ� 
	
	//���� \n ���� �����ڷ� ����Ѵ�  
	return 0;
 } 
