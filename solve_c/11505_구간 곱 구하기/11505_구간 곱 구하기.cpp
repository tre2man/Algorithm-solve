#include <iostream>
#include <math.h>
using namespace std;

/*
2042_구간 합 구하기를 응용한 문제
*/

#define MOD 1000000007

typedef long long ll;

ll arr[1000001];
ll tree[4000001];
ll N, M, K;
ll x, y;

/* 
현재 탐색 노드, 시작점, 종료점, 찾으려고 하는 인덱스, 값 차이 
범위에 벗어나는 경우 return tree[index], 부모 노드가 양쪽 두 자식 값을 통해 곱을 재 연산 해야함.
*/
ll update_segtree(int node, int start, int end, int index, ll value)
{
    /* 찾으려고 하는 인덱스가 범위 내 없을 경우 */
    if (start > index || index > end)
        return tree[node];
    /* 리프 노드이면, value 값으로 바꾼다. */
    if (start == end)
        return tree[node] = value;
    /* 리프 노드가 아니면, 계속 탐색한다. */
    int mid = (start + end) / 2;
    ll left = update_segtree(node * 2, start, mid, index, value);
    ll right = update_segtree(node * 2 + 1, mid + 1, end, index, value);
    return (tree[node] = (left * right) % MOD);
}

/* 현재 탐색 노드, 해당 노드가 포함하는 범위, 우리가 구하고자 하는 범위 */
ll find_mul(int node, int start, int end, int left, int right)
{
    /* 범위에서 벗어날경우 */
    if (left > end || right < start)
        return (1);
    /* 범위 안에 완전히 있을 경우 */
    if (left <= start && end <= right)
        return (tree[node]);
    /* 나머지 경우에 대해서는 계속 탐색 */
    int mid = (start + end) / 2;
    ll res_left = find_mul(node * 2, start, mid, left, right);
    ll res_right = find_mul(node * 2 + 1, mid + 1, end, left, right);
    return ((res_left * res_right) % MOD);
}

/* 현재 탐색 노드, 시작점, 종료점 */
ll make_segtree(int node, int start, int end)
{
    if (start == end)
        return (tree[node] = arr[start] % MOD);
    int mid = (start + end) / 2;
    ll left = make_segtree(node * 2, start, mid);
    ll right = make_segtree(node * 2 + 1, mid + 1, end);
    tree[node] = (left * right) % MOD;
    return (tree[node]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 0;
    ll a, b, c;

    cin >> N >> M >> K;
    while (i < N)
        cin >> arr[i++];
    make_segtree(1, 0, N - 1);
    i = 0;
    while (i++ < M + K)
    {
        cin >> a >> b >> c;
        /* arr는 1부터 시작하므로, 인덱스 - 1을 한다. */
        if (a == 1)
            update_segtree(1, 0, N - 1, b - 1, c);
        /* b번재 수부터 c번째 수까지의  곱을 출력 */
        else
            cout << find_mul(1, 0, N - 1, b - 1, c - 1) << "\n";
    }
    return (0);
}