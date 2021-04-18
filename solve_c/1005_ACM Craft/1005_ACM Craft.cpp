#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

/*
bfs를 이용해서 풀이.
시작 노드가 1이 아닐수도 있음을 유의하자.
입력을 받을 떄 종료 노드에 체크를 해 두고, 체크하지 않은 노드를 큐에 넣어서 탐색을 시작한다.
*/

typedef struct
{
    int end;
    int value;
} info;

void bfs()
{
    vector<info> input[1001];
    int start_point[1001];
    int visited[1001];
    int values[1001];
    queue<int> q;
    int N, K, a, b, out_index;

    memset(visited, 0, sizeof(visited));
    memset(start_point, 0, sizeof(start_point));
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> values[i];
    /* 시작점이 아닌 곳에 값 ++ */
    for (int i = 1; i <= K; i++)
    {
        cin >> a >> b;
        input[a].push_back({b, values[b]});
        start_point[b]++;
    }
    /* 0인 곳을 시작점으로 생각하고 큐에 삽입한다. */
    for (int i = 1; i <= N; i++)
    {
        if (!start_point[i])
        {
            visited[i] = values[i];
            q.push(i);
        }
    }
    cin >> out_index;
    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        for (auto i = input[start].begin(); i != input[start].end(); i++)
        {
            int next = (*i).end;
            start_point[next]--;
            /* 다음 노드의 합이 이전 노드의 값 + 다음 노드의 가중치 보다 작을 때 */
            if (visited[next] < visited[start] + (*i).value)
                visited[next] = visited[start] + (*i).value;
            if (!start_point[next])
                q.push(next);
        }
    }
    cout << visited[out_index] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--)
        bfs();
    return (0);
}