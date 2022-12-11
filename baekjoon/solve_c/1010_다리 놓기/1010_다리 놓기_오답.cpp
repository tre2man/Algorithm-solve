#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*
재귀함수를 이용해서 풀이했음.
시간초과로 풀이 안됨
*/

int cal(int n, int m)
{
    int a, b, sum;

    a = min(n, m);
    b = max(n, m);
    sum = 1;
    if (n == 1 || m == 1)
        return (b);
    else
    {
        for (int i = b - 1; i >= a; i--)
            sum += cal(a - 1, i);
        return (sum);
    }
}

int main()
{
    int t, n, m;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", cal(n, m));
    }
    return (0);
}