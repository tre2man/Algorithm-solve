#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*
bfs 돌릴때마다 치즈 확인
있으면 탐색 종료
*/

typedef struct
{
    int x;
    int y;
} loc;

int map[101][101];
int visited[101][101];
loc moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int M, N, now_cheeze = 0, last_cheeze = 0, time = 0;

void bfs()
{
    queue<loc> q;
    memset(visited, 0, sizeof(visited));
    visited[0][0] = 1;
    q.push({0, 0});
    while (!q.empty())
    {
        loc start = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            loc next = {start.x + moves[i].x, start.y + moves[i].y};
            /* 인덱스 벗어나지 않는지 */
            if (next.x >= 0 && next.x < M && next.y >= 0 && next.y < N)
            {
                /* 방문하지 않은 곳이면 */
                if (!visited[next.x][next.y])
                {
                    visited[next.x][next.y] = 1;
                    /* 방문한 곳이 치즈라면? */
                    if (map[next.x][next.y] == 1)
                    {
                        map[next.x][next.y] = 0;
                        now_cheeze--;
                    }
                    /* 방문한 곳이 치즈가 아니라면? */
                    else
                        q.push({next.x, next.y});
                }
            }
        }
    }
    time++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                now_cheeze++;
        }
    }
    while (now_cheeze)
    {
        last_cheeze = now_cheeze;
        bfs();
    }
    cout << time << "\n";
    cout << last_cheeze;
    return (0);
}