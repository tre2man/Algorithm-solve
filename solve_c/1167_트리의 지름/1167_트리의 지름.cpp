#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_LEN 100001

/*
dfs 탐색을 이용한 문제.
탐색을 해서 가장 먼 노드를 찾고 거기서 한번 더 탐색한다.
10만x10만 배열을 선언이 안된다. vector 자료형을 이용해 탐색을 진행한다. 
*/

typedef struct
{
    int node;
    int len;
} location;

vector<location> map[MAX_LEN];
bool visit[MAX_LEN];
int V, ans = 0, far_max_node = 0;

/* 탐색 노드 번호, 현재 최대 길이 */
void dfs(int node, int len)
{
    if (visit[node])
        return;
    /* 해당 노드 방문 */
    visit[node] = 1;
    if (ans < len)
    {
        ans = len;
        //최대길이 업데이트
        far_max_node = node;
    }
    /* 해당 라인에 있는 모든 원소 탐색 */
    for (int i = 0; i < map[node].size(); i++)
        dfs(map[node][i].node, len + map[node][i].len);
}

int main()
{
    int point_start, point_end, len;

    scanf("%d", &V);
    for (int i = 0; i < V; i++)
    {
        scanf("%d", &point_start);
        while (1)
        {
            scanf("%d", &point_end);
            if (point_end == -1)
                break;
            scanf("%d", &len);
            location temp;
            temp.node = point_end;
            temp.len = len;
            map[point_start].push_back(temp);
        }
    }
    /* memeset 을 이용한 배열 초기화 (0으로) 바이트 단위로 초기화 하므로 0,-1 이외의 초기화 불가능*/
    memset(visit, 0, sizeof(visit));
    dfs(1, 0);
    /* 방문 기록 초기화 */
    memset(visit, 0, sizeof(visit));
    ans = 0;
    dfs(far_max_node, 0);
    printf("%d", ans);
    return (0);
}