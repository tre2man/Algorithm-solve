#include <iostream>

/*
c언어로 못풀겠어요...오버플로우 처리를 생각해야 하는데, 나중에 해봐야 할듯
파이썬으로 풀이 했습니다.
*/

unsigned long long input, check, ans, temp;
unsigned long long powarr[17];
int end;

void cal(int start)
{
    if (end)
        return;
    for (unsigned long long i = 0; i <= 9; i += 1)
    {
        check = ans + i * powarr[start];
        check *= check;
        check %= powarr[start + 1];
        check *= (ans + i * powarr[start]);
        if ((input % powarr[start + 1]) == (check % powarr[start + 1]))
        {
            ans = ans + i * powarr[start];
            if (input == (check % powarr[start + 1]))
            {
                end = 1;
                return;
            }
            cal(start + 1);
        }
    }
}

int main()
{
    int T;

    scanf("%d", &T);
    powarr[0] = 1;
    for (int i = 1; i < 17; i++)
        powarr[i] = powarr[i - 1] * 10;
    for (int i = 0; i < T; i++)
    {
        check = ans = 0;
        end = 0;
        scanf("%lld", &input);
        cal(0);
        printf("%lld\n", ans);
    }
    return (0);
}