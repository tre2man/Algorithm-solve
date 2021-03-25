#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
일반적인 bfs 기법 적용
입력 받을때 시작점이 되는 좌표를 모조리 queue에 넣어둔다.
dfs 실행시 알아서 시작이 된다.
-1은 입력시 체크하고 사방으로 0이 되는 곳을 탐색, 그곳에 익지 않은 토마토 있다면 -1 출력.
*/

int map[1000][1000];
int visit[1000][1000];
int xarr[4] = {-1, 1, 0, 0};
int yarr[4] = {0, 0, -1, 1};
int M, N, ans;
/* 일반 탐색과 벽 탐색을 위한 큐 */
queue<pair<int, int>> q;
queue<pair<int, int>> error;

void bfs()
{
    ans = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = x + xarr[i];
            int dy = y + yarr[i];
            if (dx >= 0 && dx < N && dy >= 0 && dy < M)
            {
                if (visit[dx][dy] == 0 && map[dx][dy] == 0)
                {
                    visit[dx][dy] = visit[x][y] + 1;
                    if (visit[dx][dy] > ans)
                        ans = visit[dx][dy];
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
}

/* 익지 않은 토마토를 찾기 위한 코드 */
int check()
{
    while(!error.empty())
    {
        int x=error.front().first;
        int y=error.front().second;
        error.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = x + xarr[i];
            int dy = y + yarr[i];
            if (dx >= 0 && dx < N && dy >= 0 && dy < M)
                if (visit[dx][dy] == 0 && map[dx][dy] == 0)
                    return (0);
        }
    }
    return (1);
}

void clear()
{
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            visit[i][j] = 0;
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visit[i][j] = 1;
            }
                
            if (map[i][j] == -1)
                error.push(make_pair(i, j));
        }
    }
    bfs();
    if(!check())
        printf("-1\n");
    else if (ans)
        printf("%d\n", ans-1);
    else
        printf("0\n");
}