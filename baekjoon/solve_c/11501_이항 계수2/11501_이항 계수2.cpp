#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	int arr[1001][1001];

	memset(arr, 0, sizeof(arr));
	cin >> N >> K;
	for (int i = 0; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == 0)
				arr[i][j] = 1;
			else if (i > 0 && j > 0)
				arr[i][j] = (arr[i - 1][j - 1] + arr[i][j - 1]) % 10007;
		}
	}
	cout << arr[K][N];
	return (0);
}