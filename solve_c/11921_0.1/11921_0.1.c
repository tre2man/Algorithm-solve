#include <stdio.h>
#include <stdlib.h>

/*
미완성
*/

#define MAX_SIZE 1 << 20

int main()
{
    char *input = (char*)malloc(sizeof(char)*MAX_SIZE);
    int N,flag = 0;

    scanf("%d",&N);
    fread(input, 10, 1,stdin);
    printf("%s",input);
}