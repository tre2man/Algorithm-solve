#include <iostream>
#include <queue>
using namespace std;

#define MAP_MAX 100
#define D_MAX 4

int map[MAP_MAX][MAP_MAX];
int visit[MAP_MAX][MAP_MAX];
int dx[D_MAX] = {-1, 1, 0, 0};
int dy[D_MAX] = {0, 0, -1, 1};
int N, M;

/*
pair
두 개의 변수를 저장할 수 있는 구조
2차원 배열 인덱스, 좌표, 최단거리를 묶어서 저장할 경우
*/

void bfs()
{
    int x, y;
    queue<pair<int, int>> q;

    x = y = 0;
    q.push(make_pair(x, y));
    visit[x][y] = 1;

    /*queue가 빌 때까지 이 과정을 계속 반복한다.*/
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            /*미로의 범위에 있을 경우*/
            if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)
            {
                /*길이 존재하고 이전에 방문한 적이 없는 경우*/
                if (map[next_x][next_y] == 1 && visit[next_x][next_y] == 0)
                {
                    visit[next_x][next_y] = visit[x][y] + 1; //다음 방문지는 이전 방문지 + 1
                    q.push(make_pair(next_x, next_y)); //큐에 데이터 집어넣기
                }
            }
        }
    }
}

void input()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &map[i][j]);
}

int main()
{
    scanf("%d %d", &N, &M);
    input();
    bfs();
    printf("%d\n", visit[N - 1][M - 1]);
}