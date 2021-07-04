#include <bits/stdc++.h>
#define MAX 32000
using namespace std;

/*
기본적인 위상정렬 문제.
특정 우선순위에 대하여 백터에 저장한다.
그것을 기본으로 위상정렬을 시작한다.
이에 해당하지 않는 원소는 무작위로 출력한다.
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<int> q;
	vector<int> v[MAX + 1];
	int dgree[MAX + 1];
	int n, m, a, b;

	memset(dgree, 0, sizeof(dgree));
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		v[a].push_back(b);
		dgree[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dgree[i])
			q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		cout << now << " ";
		q.pop();
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (!(--dgree[next]))
				q.push(next);
		}
	}

	return (0);
}