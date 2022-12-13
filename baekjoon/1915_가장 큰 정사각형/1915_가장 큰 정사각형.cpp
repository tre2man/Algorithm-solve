#include <iostream>
using namespace std;

int map[1001][1001];
int dp[1001][1001];
int ans = 0;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
            if (!i || !j)
            {
                dp[i][j] = map[i][j];
                if (dp[i][j])
                    ans = 1;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (!map[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            if (dp[i][j] > ans)
                ans = dp[i][j];
        }
    }
    printf("%d", ans * ans);
}