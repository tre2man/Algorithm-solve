#include <iostream>
#include <cstring>
using namespace std;

/*
최적해가 입력사례를 분할한 부분사례에 대한 최적해를 항상 포함한다? -> 최적의 원리가 통한다.
가방의 한도를 1씩 늘리고 넣을 수 있는 물건의 무게를 1개씩 늘려 가며 최적해를 구한다.
*/

int N, K;
int dp[105][100005], weight[105], value[105];

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &weight[i], &value[i]);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            /* 현재 물건의 무게보다 가방의 무게가 더 작은 경우 */
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            /* 현재 물건의 무게보다 가방의 무게가 더 큰 경우 */
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    printf("%d", dp[N][K]);
    return (0);
}