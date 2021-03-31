#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

/*
다익스트라 알고리즘을 이용하여 탐색한다.
미완성
*/

typedef struct
{
    int node;
    int len;
} location;

vector<location> input[300001];
queue<location> open;
int V, E, K, u, v, w;

void dik(int start, int end)
{
    if (start == end)
    {
        printf("0\n");
        return;
    }
    else
    {
        open.push({1, 0});
        while (!open.empty())
        {
            int now_node = open.front().node;
            int before_len = open.front().len;
            open.pop();
            for (int i = 0; i < input[now_node].size(); i++)
            {
                int new_len = input[now_node][i].len;
                int before_len = input[now_node][i].len;
                /* 길이를 더한 값이 이전 최소 길이보다 작을 경우? 큐에 삽입 */
                if ()
                {
                    
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &V, &E, &K);
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        location temp;
        temp.node = v;
        temp.len = 1;
        input[u].push_back(temp);
    }
    for (int i = 1; i <= V; i++)
        dik(K, i);
    return (0);
}