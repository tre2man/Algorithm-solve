#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct
{
	ll x, y;
} point;

vector<point> v;

/* 양수 : 반시계 방향, 음수 : 시계 방향, 0 : 일직선, 결과값 : 두 길이 * 사인값*/
ll ccw(point a, point b, point c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

/* y축 오름차순으로 정렬함수 */
bool comp_y(point a, point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	else
		return (a.y < b.y);
}

bool comp_angle(point a, point b)
{
	ll w = ccw(v[0], a, b);
	/* 일직선이 아니라면, 각도가 작은 순으로 정렬 */
	if (w)
		return w > 0;
	/* 일직선일 경우, 거리가 작은 곳부터 */
	else
		return (a.x + a.y) < (b.x + b.y);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<point> s;
	point first, second;
	int n, x, y;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({x, y});
	}
	/* y축 오름차순으로 정렬하기 */
	sort(v.begin(), v.end(), comp_y);
	/* 각도 기준으로 정렬하기 */
	sort(v.begin() + 1, v.end(), comp_angle);

	s.push(v[0]);
	s.push(v[1]);
	/* 각도 작은곳부터 시작하기 */
	for (int i = 2; i < n; i++)
	{
		while (s.size() >= 2)
		{
			second = s.top();
			s.pop();
			first = s.top();
			/* 반시계 방향일 경우 볼록 껍질이 성립한다. */
			if (ccw(first, second, v[i]) > 0)
			{
				s.push(second);
				break;
			}
		}
		s.push(v[i]);
	}

	cout << s.size();
	return (0);
}