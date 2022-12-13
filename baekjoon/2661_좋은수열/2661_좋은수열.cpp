#include <iostream>
#include <algorithm>

int arr[81];
int N, end;

void print(int len)
{
    for (int i = 1; i < len; i++)
        printf("%d", arr[i]);
    printf("\n");
}

/* 탐색할 곳이 좋은 문자열인지 아닌지 */
int is_good(int start, int len)
{
    int i, ans = 0;
    for (i = start; i < start + len; i++)
    {
        if (arr[i] == arr[i + len])
            ans++;
    }
    if (ans == len)
        return (0);
    else
        return (1);
}

/* 좋은수열인지 아닌지 확인하는 함수 */
/* 1번 인덱스 부터 max 까지 */
int good_check(int max)
{
    /* 몇 줄짜리 검사 */
    for (int i = 1; i <= max / 2; i++)
    {
        /* 몇 번부터 검사 */
        for (int j = 1; j <= max - (i * 2) + 1; j++)
        {
            if(!is_good(j, i))
                return (0);
        }
    }
    return (1);
}

/* 백트래킹을 이용해서 하나씩 탐색, 조건에 맞으면 다음 탐색 진행함 */
void cal(int index)
{
    int num = 1;
    /* 이미 답을 찾았을 경우에는 종료 */
    if (end)
        return;
    /* 첫번째 답을 찾았을 경우에 end 플래그에 1 대입 */
    if ((index == N + 1) && !end)
    {
        print(index);
        end = 1;
        return;
    }
    while (num <= 3)
    {
        arr[index] = num;
        if (good_check(index))
            cal(index + 1);
        num++;
    }
}

int main()
{
    scanf("%d", &N);
    end = 0;
    cal(1);
    return (0);
}