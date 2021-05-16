#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535

/* 푸는중인데 44퍼에서 계속 틀림 특정 데이터에서 hull에 좌표가 2개 들어가는것 발견함.*/

typedef double db;

typedef struct
{
	db x, y;
} point;

vector<point> v;

/* 양수 : 반시계 방향, 음수 : 시계 방향, 0 : 일직선, 결과값 : 두 길이 * 사인값*/
db ccw(point a, point b, point c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

/* 위치백터의 길이 */
db uveclen(point a)
{
	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

/* 점 두개의 거리 */
db len(point a, point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

/* 내적을 이용한 각도 계산 */
db angle(point a, point b, point c)
{
	point i, j;
	db ans;
	i.x = a.x - b.x;
	i.y = a.y - b.y;
	j.x = c.x - b.x;
	j.y = c.y - b.y;

	ans = acos((i.x * j.x + i.y * j.y) / (uveclen(i) * uveclen(j)));
	return (ans);
}

/* y축 오름차순으로 정렬함수 */
bool comp_y(point a, point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	else
		return (a.y < b.y);
}

/* 작은 각도부터 정렬하기 */
bool comp_angle(point a, point b)
{
	db w = ccw(v[0], a, b);
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

	vector<point> hull;
	point first, second;
	db x, y, l, angles = 0, wall = 0;
	int n;

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({x, y});
	}
	/* y축 오름차순으로 정렬하기 */
	sort(v.begin(), v.end(), comp_y);
	/* 각도 기준으로 정렬하기 */
	sort(v.begin() + 1, v.end(), comp_angle);

	hull.push_back(v[0]);
	hull.push_back(v[1]);
	/* 각도 작은곳부터 시작하기 */
	for (int i = 2; i < n; i++)
	{
		while (hull.size() >= 2)
		{
			second = hull.back();
			hull.pop_back();
			first = hull.back();
			/* 반시계 방향일 경우 볼록 껍질이 성립한다. */
			if (ccw(first, second, v[i]) > 0)
			{
				hull.push_back(second);
				break;
			}
		}
		hull.push_back(v[i]);
	}
	for (int i = 0; i < hull.size(); i++)
		cout << hull[i].x << " " << hull[i].y << "\n";
	for (int i = 2; i < hull.size(); i++)
	{
		angles += (PI - angle(hull[i - 2], hull[i - 1], hull[i]));
		wall += len(hull[i - 1], hull[i]);
	}
	angles += PI - angle(hull[hull.size() - 2], hull[hull.size() - 1], hull[0]);
	angles += PI - angle(hull[hull.size() - 1], hull[0], hull[1]);
	wall += len(hull[0], hull[1]);
	wall += len(hull[0], hull[hull.size() - 1]);
	wall += l * angles;
	cout << round(wall);
	return (0);
}