#include <stdio.h>
 
int main(void)
{
    int num;
    char ch;
 
    //���� �Է� �� ���
    printf("����: ");
    scanf("%d", &num);
 
    printf("�Է��� ����: %d", num);
 
    //���� �Է� �� ���
    printf("����: ");
    ch = getchar();
    printf("�Է��� ����:%c ASCII CODE: %d\n", ch, ch);
 
    //���� �Է� �� ���
    printf("����: ");
    scanf("%d", &num);
    printf("�Է��� ����: %d\n", num);
 
    printf("����: ");
    fflush(stdin); //ǥ�� �Է� ��Ʈ���� ���۸� ���
                   //���� �Է� �� ���
    getchar();
    ch = getchar();
    printf("�Է��� ����:%c ASCII CODE: %d\n", ch, ch);
    return 0;
}



