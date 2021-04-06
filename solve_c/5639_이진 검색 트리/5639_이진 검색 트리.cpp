#include <iostream>
#include <cstring>

/*
재귀함수를 이용해 배열을 분할하여 푸는 문제.
*/

int arr[100001];
int num = 0;

void explore(int left, int right)
{
    if (left > right)
        return;

    int i = left + 1;
    /* 나눠줄 기준점을 찾는다. */
    while (arr[left] > arr[i] && i < num)
        i++;
    /* 왼쪽 탐색 */
    explore(left + 1, i - 1);
    /* 오른쪽 탐색 */
    explore(i, right);
    printf("%d\n", arr[left]);
}

int main()
{
    memset(arr, 0, sizeof(arr));
    while (scanf("%d", &arr[num]) > 0)
        num++;
    explore(0, num - 1);
    return (0);
}