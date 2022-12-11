#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*
bfs 탐색으로 푼다.
2차원 지도가 아닌 1차원 배열로 생각해서 풀이한다.
탐색 지점을 queue에 push 후 차례대로 pop한 다음에 조건식에 맞으면 다음 지점을 queue에 push
*/

void cal(int N, int K)
{
    queue<int> q;
    int visit[110000];
    memset(visit, 0, sizeof(visit));

    q.push(N);
    visit[N] = 1;
    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        /* 답일 경우에 출력 */
        if (start == K)
        {
            printf("%d",visit[start] - 1);
            return;
        }
        /* 인덱스 범위를 넘지 않도록 조건식을 세운다. */
        if (start - 1 >= 0 && !visit[start - 1])
        {
            visit[start - 1] = visit[start] + 1;
            q.push(start - 1);
        }
        if (start + 1 < 110000 && !visit[start + 1])
        {
            visit[start + 1] = visit[start] + 1;
            q.push(start + 1);
        }
        if (start * 2 < 110000 && !visit[start * 2])
        {
            visit[start * 2] = visit[start] + 1;
            q.push(start * 2);
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