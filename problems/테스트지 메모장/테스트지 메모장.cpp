#include <string.h>
#include <stdio.h>
 
int main(void)
{
    int arr[10];
    int i;
 
    printf("== ���� �� ==\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);//������ �� ���
    }
    printf("\n");
 
    memset(arr,1,10*sizeof(int));//arr�� �޸𸮸� 0���� ����
    printf("== ���� �� ==\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");   
 
    return 0;
}


