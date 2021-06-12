#include <bits/stdc++.h>
using namespace std;

#define DP 1

#ifdef DP
//dp
int dp(int a)
{
	int arr[1000001] = {0};
	if (a == 1)
		return arr[0];
	for (int i = 2; i <= a; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}
	return arr[a];
}

int main()
{
	int a;
	cin >> a;
	cout << dp(a);
	return (0);
}
#endif


#ifdef BFS
//bfs

unsigned int visited[1000001];

int bfs(int a)
{
	queue<int> q;
	q.push(a);
	visited[a] = 1;
	while (!q.empty())
	{
		int start = q.front();
		q.pop();
		if (start == 1)
			return (visited[start] - 1);
		if ((start / 3 > 0) && !(start % 3) && (visited[start / 3] > visited[start]))
		{
			visited[start / 3] = visited[start] + 1;
			q.push(start / 3);
		}
		if ((start / 2 > 0) && !(start % 2) && (visited[start / 2] > visited[start]))
		{
			visited[start / 2] = visited[start] + 1;
			q.push(start / 2);
		}
		if ((start - 1 > 0) && (visited[start - 1] > visited[start]))
		{
			visited[start - 1] = visited[start] + 1;
			q.push(start - 1);
		}
	}
	return (0);
}

int main()
{
	int a;
	memset(visited, 0xFF, sizeof(visited));
	cin >> a;
	cout << bfs(a);
	return (0);
}
#endif