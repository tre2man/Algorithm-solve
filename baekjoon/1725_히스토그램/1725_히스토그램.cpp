#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*
넓이를 판별하는 기준 : 이전의 높이가 현재 높이보다 클 경우
답 : max(이전 답, 새로운 사각형의 넓이)
재풀이 필요함.
*/

int N, ans, h[100002];
stack<int> s;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &h[i]);
    s.push(0);
    for (int i = 1; i <= N + 1; i++)
    {
        while (!s.empty() && h[s.top()] > h[i])
        {
            int check = s.top();
            s.pop();
            ans = max(ans, h[check] * (i - s.top() - 1));
        }
        s.push(i);
    }
    printf("%d", ans);
    return (0);
}