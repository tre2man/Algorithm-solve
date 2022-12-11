#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[1000111];

ll check(ll checkNow, ll N)
{
	ll ans = 0;
	for (int i = 1; i <= N; i++)
		if (arr[i] - checkNow > 0)
			ans += (arr[i] - checkNow);
	return (ans);
}

ll find(ll front, ll rear, ll N, ll H)
{
	cout << front << " " << rear << "\n";
	ll mid, temp;
	if (front == rear)
	{
		temp = check(front, N);
		return (front);
	}
	mid = (front + rear) / 2;
	temp = check(mid, N);
	if (temp == H)
		return (mid);
	else if (temp < H)
		return (find(front, mid, N, H));
	else
		return (find(mid + 1, rear, N, H));
}

int main()
{
	ll N, H, maxnum = 0, checkNow, temp;
	cin >> N >> H;
	for (ll i = 1; i <= N; i++)
	{
		cin >> arr[i];
		maxnum = max(maxnum, arr[i]);
	}
	cout << find(0, maxnum, N, H);
	return (0);
}