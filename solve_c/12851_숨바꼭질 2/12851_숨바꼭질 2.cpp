#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*
1679_숨바꼭질 문제의 응용 버전.
가장 빠른 시간으로 찾는 방법의 가짓수도 출력한다.
*/

void cal(int N, int K)
{
    queue<int> q;
    int visit[110000];
    int ans = 0;
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
            printf("%d\n%d", visit[start] - 1, ans);
            return;
        }
        /* 인덱스 범위를 넘지 않도록 조건식을 세운다. */
        if (start - 1 >= 0 && !visit[start - 1])
        {
            visit[start - 1] = visit[start] + 1;
            if (start - 1 == K)
                ans++;
            q.push(start - 1);
        }
        if (start + 1 < 110000 && !visit[start + 1])
        {
            visit[start + 1] = visit[start] + 1;
            if (start + 1 == K)
                ans++;
            q.push(start + 1);
        }
        if (start * 2 < 110000 && !visit[start * 2])
        {
            visit[start * 2] = visit[start] + 1;
            if (start * 2 == K)
                ans++;
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