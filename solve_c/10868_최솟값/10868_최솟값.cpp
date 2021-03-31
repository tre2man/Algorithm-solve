#include <iostream>

#define INT_MAX 2147483647

using namespace std;

int arr[100001];
int tree[400001];

/* 해당 노드, 해당 노드가 포함하는 범위, 찾으려는 범위 */
int find_min(int node, int start, int end, int left, int right)
{
    /* 범위에서 벗어날 경우 */
    if (left > end || start > right)
        return (INT_MAX);
    /* 범위에 완전히 안착할 경우 */
    if (left <= start && end <= right)
        return (tree[node]);
    int mid = (start + end) / 2;
    int res_left = find_min(node * 2, start, mid, left, right);
    int res_right = find_min(node * 2 + 1, mid + 1, end, left, right);
    return (min(res_left, res_right));
}

/* 세그먼트 트리 만들기 */
int make_tree(int node, int start, int end)
{
    if (start == end)
        return (tree[node] = arr[start]);
    int mid = (start + end) / 2;
    int left = make_tree(node * 2, start, mid);
    int right = make_tree(node * 2 + 1, mid + 1, end);
    tree[node] = min(left, right);
    return (tree[node]);
}

int main()
{
    int M, N, a, b;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    make_tree(1, 0, N - 1);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", find_min(1, 0, N - 1, a - 1, b - 1));
    }
    return (0);
}