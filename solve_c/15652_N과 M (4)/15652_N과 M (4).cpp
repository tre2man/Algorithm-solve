#include <iostream>

/*
백트래킹을 이용하여 풀 수 있는 간단한 문제이다.
반복문의 시작점을 start, M이 될때까지 반복
재귀 함수를 부를 때 count + 1을 한다.
*/

int arr[8];
int M, N;

void print()
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void back(int start, int count)
{
    if (count == N)
    {
        print();
        return;
    }
    for (int i = start; i <= M; i++)
    {
        arr[count] = i;
        back(i, count + 1);
    }
}

int main()
{
    scanf("%d %d", &M, &N);
    back(1, 0);
    return (0);
}