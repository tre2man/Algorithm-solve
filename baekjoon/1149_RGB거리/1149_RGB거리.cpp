#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
현재 집에서 최소의 비용을 누적
*/

int visit[3][1000];
int house[3][1000];
int N;

void cal()
{
    visit[0][0] = house[0][0];
    visit[1][0] = house[1][0];
    visit[2][0] = house[2][0];
    for (int i = 1; i < N; i++)
    {
        visit[0][i] = house[0][i] + min(visit[1][i - 1], visit[2][i - 1]);
        visit[1][i] = house[1][i] + min(visit[0][i - 1], visit[2][i - 1]);
        visit[2][i] = house[2][i] + min(visit[0][i - 1], visit[1][i - 1]);
    }
    printf("%d", min(visit[0][N - 1], min(visit[1][N - 1], visit[2][N - 1])));
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d %d", &house[0][i], &house[1][i], &house[2][i]);
    cal();
    return (0);
}