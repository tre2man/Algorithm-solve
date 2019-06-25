#include <stdio.h>
 
int main(void)
{
    int num;
    char ch;
 
    //정수 입력 및 출력
    printf("정수: ");
    scanf("%d", &num);
 
    printf("입력한 정수: %d", num);
 
    //문자 입력 및 출력
    printf("문자: ");
    ch = getchar();
    printf("입력한 문자:%c ASCII CODE: %d\n", ch, ch);
 
    //정수 입력 및 출력
    printf("정수: ");
    scanf("%d", &num);
    printf("입력한 정수: %d\n", num);
 
    printf("문자: ");
    fflush(stdin); //표준 입력 스트림의 버퍼를 비움
                   //문자 입력 및 출력
    getchar();
    ch = getchar();
    printf("입력한 문자:%c ASCII CODE: %d\n", ch, ch);
    return 0;
}



