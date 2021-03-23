#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*
10으로 나눈 나머지를 출력하면 된다.
반복문이 실행되지 않는 경우에 대해서 예외처리한다.
*/

void cal(int a, int b)
{
    int ans;

    ans = ((a - 1) % 10) + 1;
    while (b-- > 1)
        ans = ((ans * a - 1) % 10) + 1;
    printf("%d\n", ans);
}

int main()
{
    int t, a, b;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        cal(a, b);
    }
    return (0);
}