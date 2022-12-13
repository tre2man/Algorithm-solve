#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAP_MAX 1001
#define D_MAX 4

int map[MAP_MAX][MAP_MAX];
int visit[MAP_MAX][MAP_MAX][2];
int dx[D_MAX] = {-1, 1, 0, 0};
int dy[D_MAX] = {0, 0, -1, 1};
int N, M, ans;

typedef struct
{
    int x;
    int y;
    int broken;
} wall;

//bfs 수행 및 방문한곳 표시
int bfs()
{
    wall start;
    queue<wall> q;

    start.x = start.y = 0;
    /*벽을 부술수 있는 남은 기회의 수*/
    start.broken = 1;
    q.push(start);
    visit[start.x][start.y][start.broken] = 1;

    /*queue가 빌 때까지 이 과정을 계속 반복한다.*/
    while (!q.empty())
    {
        start.x = q.front().x;
        start.y = q.front().y;
        start.broken = q.front().broken;
        q.pop();

        if (start.x == N - 1 && start.y == M - 1)
            return (visit[start.x][start.y][start.broken]);

        for (int i = 0; i < 4; i++)
        {
            wall next;
            next.x = start.x + dx[i];
            next.y = start.y + dy[i];
            /*탐색하려는 곳이 미로의 범위 안에 있을 경우*/
            if (0 <= next.x && next.x < N && 0 <= next.y && next.y < M)
            {
                /*벽인 동시에 파괴한 적이 없을 경우*/
                if (map[next.x][next.y] == 1 && start.broken == 1)
                {
                    visit[next.x][next.y][start.broken - 1] = visit[start.x][start.y][start.broken] + 1;
                    next.broken = 0;
                    q.push(next);
                }
                /*갈수 있는 길이고, 방문하지 않았다면*/
                else if (map[next.x][next.y] == 0 && visit[next.x][next.y][start.broken] == 0)
                {
                    visit[next.x][next.y][start.broken] = visit[start.x][start.y][start.broken] + 1;
                    next.broken = start.broken;
                    q.push(next);
                }
            }
        }
    }
    return (-1);
}

void input()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &map[i][j]);
}

int main()
{
    cin >> N >> M;
    input();
    memset(visit, 0, sizeof(visit));
    printf("%d\n", bfs());
}