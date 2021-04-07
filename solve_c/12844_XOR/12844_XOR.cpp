#include <iostream>
#include <cmath>
using namespace std;

/*
update 함수가 문제인듯. 시간초과가 계속 뜬다.
*/

int arr[1000001];
int tree[4000001];
int N, M;

/* 현재 탐색 노드, 시작점, 종료점, 찾으려고 하는 인덱스, 값 차이 */
void update_segtree(int node, int start, int end, int index, int diff)
{
    /* 찾으려고 하는 인덱스가 범위 내 없을 경우 */
    if (start > index || index > end)
        return;
    /* 찾으려고 하는 인덱스와 어느정도 겹친다 */
    tree[node] ^= diff;
    /* 리프 노드가 아니면, 계속 탐색한다. */
    if (start != end)
    {
        int mid = (start + end) / 2;
        update_segtree(node * 2, start, mid, index, diff);
        update_segtree(node * 2 + 1, mid + 1, end, index, diff);
    }
}

/* 현재 탐색 노드, 해당 노드가 포함하는 범위, 우리가 구하고자 하는 범위 */
int find_xor(int node, int start, int end, int left, int right)
{
    /* 범위에서 벗어날경우 */
    if (left > end || right < start)
        return (0);
    /* 범위 안에 완전히 있을 경우 */
    if (left <= start && end <= right)
        return (tree[node]);

    int mid = (start + end) / 2;
    int res_left = find_xor(node * 2, start, mid, left, right);
    int res_right = find_xor(node * 2 + 1, mid + 1, end, left, right);
    return (res_left ^ res_right);
}

/* 현재 탐색 노드, 시작점, 종료점 */
int make_segtree(int node, int start, int end)
{
    if (start == end)
        return (tree[node] = arr[start]);
    int mid = (start + end) / 2;
    int left = make_segtree(node * 2, start, mid);
    int right = make_segtree(node * 2 + 1, mid + 1, end);
    tree[node] = left ^ right;
    return (tree[node]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i = 0;
    int a, b, c, K;

    cin >> N;
    while (i < N)
        cin >> arr[i++];
    make_segtree(1, 0, N - 1);
    i = 0;
    cin >> M;
    while (i < M)
    {
        cin >> a;
        /* b~c 번째 수를 c로 변경 */
        if (a == 1)
        {
            /* arr는 1부터 시작하므로, 인덱스 - 1을 한다. */
            cin >> b >> c >> K;
            if (b > c)
                swap(b, c);
            for (int i = b; i <= c; i++)
                update_segtree(1, 0, N - 1, i, K);
        }
        /* b번재 수부터 c번째 수까지의 xor를 출력 */
        else
        {
            cin >> b >> c;
            if (b > c)
                swap(b, c);
            cout << find_xor(1, 0, N - 1, b, c) << '\n';
        }

        i++;
    }
    return (0);
}