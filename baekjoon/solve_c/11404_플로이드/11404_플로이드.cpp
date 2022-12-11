#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

/*
다익스트라 알고리즘을 응용한 플로이드-와샬 문제이다.
기본적인 구조는 다익스트라 탐색이랑 비슷하다.
출력 시 시작점 = 방문점 일 경우에 0을 출력한다.

구조에 대한 설명은 1753_최단경로 문제 참조
*/ 

typedef struct
{
    int node;
    int len;
} location;

priority_queue<location> q;
vector<location> v[101];
int min_len[100001], visited[100001];
int n, m, a, b, c;

/* 거리가 적은 것이 우선순위가 높게 한다. */
bool operator<(location a, location b)
{
    return (a.len > b.len);
}

void print_visit(int except)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == except)
            printf("0 ");
        else
            printf("%d ", min_len[i]);
    }
    printf("\n");
}

void floyd(int start)
{
    memset(min_len, 0, sizeof(min_len));
    memset(visited, 0, sizeof(visited));
    q.push({start, 0});
    while (!q.empty())
    {
        int start_node = q.top().node;
        int start_cost = q.top().len;
        q.pop();
        for (int i = 0; i < v[start_node].size(); i++)
        {
            int next_node = v[start_node][i].node;
            int next_cost = v[start_node][i].len;
            if (!visited[next_node] && !min_len[next_node] || min_len[next_node] > start_cost + next_cost)
            {
                min_len[next_node] = start_cost + next_cost;
                q.push({next_node, min_len[next_node]});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        floyd(i);
        print_visit(i);
    }
}