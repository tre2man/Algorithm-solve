#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
dp를 이용해서 푼다.
회의 시작 시간을 기준으로 오름차순으로 정렬한다.
회의 시작 시간이 같을 경우, 회의 종료 시간 기준으로 정렬한다.
dp에는 몇 번 회의 할수 있는지, end_min은 회의 종료시간의 최솟값을 저장하고, 매번 갱신한다.
*/

typedef struct
{
    int start;
    int end;
} confer;

/* 시작 시간이 같으면 종료 시간 기준으로 정렬 */
bool comp(confer a, confer b)
{
    if (a.start == b.start)
        return (a.end < b.end);
    else
        return (a.start < b.start);
}

int main()
{
    int N, end_min;
    vector<confer> q;
    vector<int> dp;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        confer input;
        scanf("%d %d", &input.start, &input.end);
        q.push_back(input);
    }
    sort(q.begin(), q.end(), comp);
    dp.push_back(1);
    end_min = q.front().end;
    for (auto start = q.begin() + 1; start != q.end(); start++)
    {
        /* 다음 회의를 진행할 수 있을 경우 */
        if (end_min <= start->start)
        {
            dp.push_back(dp.back() + 1);
            end_min = start->end;
        }
        /* 다음 회의를 진행할 수는 없지만 종료 시간이 더 빠른 경우 */
        else if (start->end < end_min)
        {
            end_min = start->end;
            dp.push_back(dp.back());
        }
    }
    printf("%d",dp.back());
}
