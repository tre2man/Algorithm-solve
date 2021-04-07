#include <iostream>
#include <cstring>
using namespace std;

#define BOARD_MAX 15

int arr[BOARD_MAX];
int sum, n;

/* 배치된 퀸이 조건에 맞는지 판별하는 함수 */
int correct(int index)
{
	int check, i = -1;

	while (++i < index)
	{
		check = arr[i] - arr[index];
		if (check < 0)
			check *= -1;
		if (arr[index] == arr[i] || check == index - i)
			return (0);
	}
	return (1);
}

/* 재귀함수가 돌아가면서 백트래킹을 실행한다. */
void rec(int start)
{
	int i = -1;

	/* 체스판에 퀸이 N개 채워졌을 경우 */
	if (start == n)
	{
		sum++;
		return;
	}
	while (++i < n)
	{
		arr[start] = i;
		if (correct(start))
			rec(start + 1);
	}
}

/* 배열 초기화 후 백트래킹 실행 */
void ten_queens_puzzle(void)
{
	int i = -1;

	sum = 0;
	memset(arr, 0, sizeof(arr));
	rec(0);
}

int main()
{
	cin >> n;
	ten_queens_puzzle();
	cout << sum;
}