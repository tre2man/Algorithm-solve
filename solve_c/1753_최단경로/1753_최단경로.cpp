#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

/*
다익스트라 알고리즘을 이용하여 탐색한다.
우선순위 큐를 이용하는 알고리즘이다. (누적된 길이의 합이 적은 것부터 시작)
max_len 을 최대숫자로 초기화하지 않는 대신, 0이 아닐 경우를 추가해준다.
*/

typedef struct
{
    int node;
    int len;
} location;

vector<location> input[300001];
/* 우선순위 큐를 이용하여 누적된 거리가 적은 것부터 뽑는다. */
priority_queue<location> open;
int min_len[300001];
int visited[300001];
int V, E, K, u, v, w;

/* 거리가 적은 것이 우선순위가 높게 한다. */
bool operator<(location a, location b)
{
    return (a.len > b.len);
}

void dijk(int start, int end)
{
    /* 시작점 초기비용 = 0 */
    open.push({start, 0});
    while (!open.empty())
    {
        /* 이전 노드의 최소 거리와 노드 정보 추출 */
        int start_node = open.top().node;
        int start_cost = open.top().len;
        visited[start_node] = 1;
        open.pop();
        /* 이웃한 노드의 거리 모두 확인 */
        for (int i = 0; i < input[start_node].size(); i++)
        {
            int next_node = input[start_node][i].node;
            int next_cost = input[start_node][i].len;
            /* 최소 경로 발견시? 큐에 삽입 */
            if (!visited[next_node] && !min_len[next_node] || min_len[next_node] > start_cost + next_cost)
            {
                /* 다음 탐색 노드에 길이 정보 입력 */
                min_len[next_node] = start_cost + next_cost;
                /* 큐에는 다음 노드의 전체 정보 push */
                open.push({next_node, min_len[next_node]});
            }
        }
    }
    for (int i = 1; i <= end; i++)
    {
        if (i != start && !min_len[i])
            printf("INF\n");
        else
            printf("%d\n", min_len[i]);
    }
}

int main()
{
    scanf("%d %d %d", &V, &E, &K);
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        input[u].push_back({v, w});
    }
    memset(min_len, 0, sizeof(min_len));
    memset(visited, 0, sizeof(visited));
    dijk(K, V);
    return (0);
}