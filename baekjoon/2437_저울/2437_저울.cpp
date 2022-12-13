#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
greedy 알고리즘 사용
정렬 한다
0부터 시작, 탐색 구간이 0+1 보다 크면 답은 1, 그렇지 않으면 계속 더해 나간다.
*/

int main()
{
    int N, temp, ans = 0;
    vector<int> v;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= N; i++)
    {
        if (v[i] > ans + 1)
            break;
        ans += v[i];
    }
    printf("%d\n", ans + 1);
}