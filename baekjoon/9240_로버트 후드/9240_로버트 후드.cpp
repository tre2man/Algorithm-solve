#include <bits/stdc++.h>
using namespace std;

/*
솔직히 이거 왜 맞았는지 모르겠음.
출제자의 의도와 상관없이 convex Hull 후에 완전탐색을 해도 답이 나온다.
*/

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

db len(point a, point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
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
    cout << fixed;
    cout.precision(7);

    vector<point> hull;
    point first, second;
    db x, y, ans = 0;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    if (n == 2)
    {
        cout << len(v[0], v[1]);
        return (0);
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
    {
        for (int j = 0; j < hull.size(); j++)
        {
            if (i != j)
            {
                db newlen = len(hull[i], hull[j]);
                if (ans < newlen)
                    ans = newlen;
            }
        }
    }
    cout << ans;
    return (0);
}