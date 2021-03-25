#include <iostream>
#include <algorithm>

int arr[81];
int N;

void print(int len)
{
    for (int i = 1; i < len; i++)
        printf("%d", arr[i]);
    printf("\n");
}

int good_check(int max)
{
    int str;
    int sum;

    /* 몇 줄짜리 검사 */
    for (int i = 1; i <= max / 2; i++)
    {
        sum = 0;
        /* 몇 번이나 검사 */
        for (int j = 1; j <= max - (i * 2); j++)
        {
            str = 0;
            for (int k = j; k < i + j; k++)
            {
                if (arr[k] == arr[k + i + j])
                    str++;
            }
            if (str == i)
                sum++;
        }
        if (sum == max - (i * 2))
            return (0);
    }
    return (1);
}

void cal(int index)
{
    int num = 1;
    if (index == N + 1)
    {
        print(index);
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
    cal(1);
}