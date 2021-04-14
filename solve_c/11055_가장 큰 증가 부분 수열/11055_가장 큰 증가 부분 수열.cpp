#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp, ans = 0;
    vector<int> input, sum;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        sum.push_back(input[i]);
        for (int j = 0; j <= i; j++)
        {
            if (input[i] > input[j])
                sum[i] = max(sum[i], input[i] + sum[j]);
        }
    }
    for (int i = 0; i < N; i++)
        if (sum[i] > ans)
            ans = sum[i];
    cout << ans;
    return (0);
}