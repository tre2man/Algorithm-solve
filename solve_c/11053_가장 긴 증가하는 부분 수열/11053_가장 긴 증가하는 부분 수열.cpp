#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
LIS 알고리즘 사용.
동적 계획법, 이진(이분) 탐색 사용 (완전탐색은 시간이 느려서 패스)
여기 문제에서는 동적 계획법을 이용한 탐색법을 사용했다.

솔직히 아직도 알고리즘이 이해가 가지 않는다.
키워드 : 백준 11053, LIS알고리즘
*/

int main()
{
    vector<int> v;
    vector<int> len;
    int N, temp, ans = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        len.push_back(1);
        for (int j = 0; j <= i; j++)
        {
            if (v[i] > v[j])
                len[i] = max(len[i], len[j] + 1);
        }
    }
    for(auto start = len.begin(); start != len.end();start++)
        ans = max(ans, *start);
    printf("%d\n",ans);
}