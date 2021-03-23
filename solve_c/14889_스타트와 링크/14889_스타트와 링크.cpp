#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*
백트래킹 탐색을 통해서 결과를 도출한다.
*/

#define INT_MAX 2147483647

int map[20][20];
int visit[20];
int ans;

void cal(int a, int num, int n)
{
    int start, link;

    start = link = 0;
    /*구분자가 n/2가 될때 비교연산 시작*/
    if (num == n / 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                /*해당 줄의 모든 값에 대하여 합을 수행한다.*/
                if (visit[i] && visit[j])
                    start += map[i][j];
                else if (!visit[i] && !visit[j])
                    link += map[i][j];
            }
        }
        /*최솟값보다 작을경우, 치환*/
        if (abs(start - link) < ans)
            ans = abs(start - link);
        return;
    }
    while (a < n)
    {
        /*백트래킹이 실행되는 공간*/
        visit[a] = 1;
        cal(a + 1, num + 1, n);
        visit[a] = 0;
        a++;
    }
}

int main()
{
    int n;

    ans = INT_MAX;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    cal(0, 0, n);
    printf("%d\n", ans);
}