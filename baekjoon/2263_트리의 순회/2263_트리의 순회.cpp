#include <iostream>

using namespace std;

int in_order[100001];
int post_order[100001];
int index[100001];

/*
이진 트리의 인오더, 포스트오더 받을시 프리오더로 탐색하는 문제
인오더는 루트 노드를 기준으로 왼쪽 오른쪽으로 재귀적으로 탐색.
포스트오더는 루트 노드가 항상 오른쪽에 존재함. 전체 루트 노드는 제일 오른쪽에 주어진다.
이를 기반으로 index 배열에 인오더의 결과값 순서를 입력하여 재귀 탐색을 실행할 시 루트 노드를 찾게 한다.
*/

void get_preorder(int in_start, int in_end, int post_start, int post_end)
{
    /* 범위를 넘어설 경우 종료 */
    if (in_start > in_end || post_start > post_end)
        return;
    int root_index = index[post_order[post_end]];
    int size_left = root_index - in_start;
    int size_right = in_end - root_index;
    printf("%d ", in_order[root_index]);
    /* 왼쪽 */
    get_preorder(in_start, root_index - 1, post_start, post_start + size_left - 1);
    /* 오른쪽 */
    get_preorder(root_index + 1, in_end, post_start + size_left, post_end - 1);
}

int main()
{
    int n;

    scanf("%d", &n);
    /* in order */
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in_order[i]);
        index[in_order[i]] = i;
    }
    /* post order */
    for (int i = 1; i <= n; i++)
        scanf("%d", &post_order[i]);
    get_preorder(1, n, 1, n);
    return (0);
}