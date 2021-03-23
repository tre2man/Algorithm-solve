#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;

/*
ans 배열에 값을 저장해 두어 값이 존재하면 그 값을 꺼내어 사용한다.
*/

int ans[31][31];

int cal(int n, int m)
{
    if (n == 1 || m == 1)
        return (max(n, m));
    if (ans[n][m])
        return (ans[n][m]);
    for (int i = m - 1; i >= n - 1; i--)
        ans[n][m] += cal(n - 1, i);
    return (ans[n][m]);
}

int main()
{
    int t, n, m;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%d %d", &n, &m);
        printf("%d\n", cal(n, m));
    }
    return (0);
}