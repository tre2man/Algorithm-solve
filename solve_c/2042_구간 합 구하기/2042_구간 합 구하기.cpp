#include <iostream>
#include <math.h>

/*
세그먼트 트리를 이용한 문제
@@@@주의@@@@
arr은 0부터 시작하고 tree는 1부터 시작한다.
*/

typedef long long ll;

ll arr[1000001];
ll tree[4000001];
ll N, M, K;

/* 현재 탐색 노드, 시작점, 종료점, 찾으려고 하는 인덱스, 값 차이 */
void update_segtree(int node, int start, int end, int index, ll diff)
{
    /* 찾으려고 하는 인덱스가 범위 내 없을 경우 */
    if (start > index || index > end)
        return;
    /* 찾으려고 하는 인덱스와 어느정도 겹친다 */
    tree[node] += diff;
    /* 리프 노드가 아니면, 계속 탐색한다. */
    if (start != end)
    {
        int mid = (start + end) / 2;
        update_segtree(node * 2, start, mid, index, diff);
        update_segtree(node * 2 + 1, mid + 1, end, index, diff);
    }
}

/* 현재 탐색 노드, 해당 노드가 포함하는 범위, 우리가 구하고자 하는 범위 */
ll find_sum(int node, int start, int end, int left, int right)
{
    /* 범위에서 벗어날경우 */
    if (left > end || right < start)
        return (0);
    /* 범위 안에 완전히 있을 경우 */
    if (left <= start && end <= right)
        return (tree[node]);

    int mid = (start + end) / 2;
    ll res_left = find_sum(node * 2, start, mid, left, right);
    ll res_right = find_sum(node * 2 + 1, mid + 1, end, left, right);
    return (res_left + res_right);
}

/* 현재 탐색 노드, 시작점, 종료점 */
ll make_segtree(int node, int start, int end)
{
    if (start == end)
        return (tree[node] = arr[start]);
    int mid = (start + end) / 2;
    ll left = make_segtree(node * 2, start, mid);
    ll right = make_segtree(node * 2 + 1, mid + 1, end);
    tree[node] = left + right;
    return (tree[node]);
}

int main()
{
    int i = 0;
    ll a, b, c;

    scanf("%d %d %d", &N, &M, &K);
    while (i < N)
        scanf("%lld", &arr[i++]);
    make_segtree(1, 0, N - 1);
    i = 0;
    while (i++ < M + K)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        /* b번째 수를 c로 변경 */
        if (a == 1)
        {
            /* arr는 1부터 시작하므로, 인덱스 - 1을 한다. */
            ll diff = c - arr[b - 1];
            arr[b - 1] = c;
            update_segtree(1, 0, N - 1, b - 1, diff);
        }
        /* b번재 수부터 c번때 수까지의 합을 출력 */
        else
            printf("%lld\n", find_sum(1, 0, N - 1, b - 1, c - 1));
    }
    return (0);
}