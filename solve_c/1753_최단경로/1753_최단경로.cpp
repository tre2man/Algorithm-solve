#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

/*
다익스트라 알고리즘을 이용하여 탐색한다.
우선순위 큐를 이용하는 알고리즘이다. (누적된 길이의 합이 적은 것부터 시작)
미완성
*/

typedef struct
{
    int node;
    int len;
} location;

vector<location> input[300001];
priority_queue<location> open;
int max_len[300001];
int visited[300001];
int V, E, K, u, v, w;

bool operator<(location a, location b)
{
    return (a.len > b.len);
}

void dijk(int start, int end)
{
    /* 시작점 초기비용 */
    open.push({start, 0});
    while (!open.empty())
    {
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
            if (!visited[next_node] && !max_len[next_node] || max_len[next_node] > start_cost + next_cost)
            {
                max_len[next_node] = start_cost + next_cost;
                open.push({next_node, max_len[next_node]});
            }
        }
    }
    for (int i = 1; i <= end; i++)
    {
        if (i != start && !max_len[i])
            printf("INF\n");
        else
            printf("%d\n", max_len[i]);
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
    memset(max_len, 0, sizeof(max_len));
    memset(visited, 0, sizeof(visited));
    dijk(K, V);
    return (0);
}