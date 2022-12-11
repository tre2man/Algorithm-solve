#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
우선순위 큐를 이용한 문제이다.
최소 카드 2개를 뽑은 후, 큐에 2개를 더한 값을 넣는다.
이 과정을 큐의 원소가 1개 남을 때까지 반복
나중에 복습 해야할듯
*/

int main()
{
    int N, temp;
    /* greater<int> : 작은값이 먼저나옴, less<int> : 큰 값이 먼저나옴 */
    /* bool operator 를 이용하여 비교도 가능 */
    priority_queue<int, vector<int>, greater<int>> pq;
    long long ans = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        pq.push(temp);
    }
    while (pq.size() > 1)
    {
        int sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        ans += sum;
        pq.push(int(sum));
    }
    printf("%lld", ans);
}