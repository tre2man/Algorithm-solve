#include <iostream>
#include <queue>
using namespace std;

/*
왼쪽 오른쪽 정렬하는 알고리즘 다시 짜자...
*/

typedef struct
{
    int map[20][20];
    int depth;
} maps;

queue<maps> q;
int ans, N;
maps (*fp[4])(maps);

void print_map(maps input)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%2d ",input.map[i][j]);
        }
        printf("\n");
    }
}

void pick_max(maps input)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (input.map[i][j] > ans)
                ans = input.map[i][j];
        }
    }
}

maps move_up(maps input)
{
    
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            /* 탐색하는 칸이 0이 아니고 아래칸이랑 같은 숫자일 경우 */
            if (input.map[i][j] == input.map[i + 1][j])
            {
                input.map[i][j] *= 2;
                /* 한칸씩 위로 이동 */
                for (int k = i + 1; k < N - 1; k++)
                    input.map[k][j] = input.map[k + 1][j];
                input.map[N - 1][j] = 0;
            }
        }
    }
    print_map(input);
    printf("\n");
    return (input);
}

maps move_down(maps input)
{
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            /* 탐색하는 칸이 0이 아니고 윗칸이랑 같은 숫자일 경우 */
            if (input.map[i][j] == input.map[i - 1][j])
            {
                input.map[i][j] *= 2;
                /* 한칸씩 아래로 이동 */
                for (int k = i - 1; k >= 1; k--)
                    input.map[k][j] = input.map[k - 1][j];
                input.map[0][j] = 0;
            }
        }
    }
    return (input);
}

maps move_right(maps input)
{
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 0; j < N; j++)
        {
            /* 탐색하는 칸이 0이 아니고 왼쪽칸이랑 같은 숫자일 경우 */
            if (input.map[j][i] == input.map[j][i - 1])
            {
                input.map[j][i] *= 2;
                /* 한칸씩 오른쪽으로 이동 */
                for (int k = j - 1; k >= 1; k--)
                    input.map[k][i] = input.map[k - 1][i];
                input.map[0][i] = 0;
            }
        }
    }
    return (input);
}

maps move_left(maps input)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            /* 탐색하는 칸이 0이 아니고 오른쪽칸이랑 같은 숫자일 경우 */
            if (input.map[j][i] == input.map[j][i + 1])
            {
                input.map[j][i] *= 2;
                /* 한칸씩 왼쪽으로 이동 */
                for (int k = j + 1; k < N - 1; k++)
                    input.map[k][i] = input.map[k + 1][i];
                input.map[N - 1][i] = 0;
            }
        }
    }
    return (input);
}

void explore()
{
    while (q.size())
    {
        maps front = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (front.depth < 5)
            {
                maps temp = fp[i](front);
                pick_max(temp);
                temp.depth++;
                q.push(temp);
                temp.depth--;
            }
        }
    }
}

int main()
{
    ans = 0;
    fp[0] = move_up;
    fp[1] = move_down;
    fp[2] = move_left;
    fp[3] = move_right;
    scanf("%d", &N);
    maps input;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &(input.map[i][j]));
        }
    }
    input.depth = 0;
    q.push(input);
    explore();
    printf("%d",ans);
}