#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INT_MAX 2147483647

/*
순간이동을 하는 경우에는 시간이 걸리지 않는다.
다익스트라 알고리즘을 이용하여 문제를 풀이한다.

우선순위 큐를 이용하여 시간이 적게 걸리는 경우부터 탐색한다.
min_time을 최댓값으로 바꾼 후 계산한다.
*/

typedef struct
{
    int location;
    int time;
} loc;

bool operator<(loc a, loc b)
{
    return (a.time > b.time);
}

void cal(int N, int K)
{
    priority_queue<loc> q;
    int min_time[110000];

    /* min_time을 모두 최댓값으로 변경 */
    for (int i = 0; i < 109999; i++)
        min_time[i] = INT_MAX;

    q.push({N, 0});
    min_time[N] = 0;
    while (!q.empty())
    {
        int start_location = q.top().location;
        int start_min = q.top().time;
        q.pop();
        /* 답을 찾았을 경우 */
        if (start_location == K)
        {
            printf("%d",min_time[K]);
            return;
        }
        /* 앞으로 2배 이동, 추가비용 없음*/
        if (start_location * 2 < 110000 && min_time[start_location * 2] > start_min)
        {
            min_time[start_location * 2] = start_min;
            q.push({start_location * 2, start_min});
        }
        /* 뒤로 1칸 이동, 비용 + 1 */
        if (start_location - 1 >= 0 && min_time[start_location - 1] > start_min + 1)
        {
            min_time[start_location - 1] = start_min + 1;
            q.push({start_location - 1, start_min + 1});
        }
        /* 앞으로 1칸 이동, 비용 + 1*/
        if (start_location + 1 < 110000 && min_time[start_location + 1] > start_min + 1)
        {
            min_time[start_location + 1] = start_min + 1;
            q.push({start_location + 1, start_min + 1});
        }
    }
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    cal(N, K);
    return (0);
}