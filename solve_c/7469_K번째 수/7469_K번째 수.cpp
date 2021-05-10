#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
실패
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp, i, j, k;
    vector<int> v, arr;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    while (m--)
    {
        cin >> i >> j >> k;
        arr = v;
        sort(arr.begin() + i - 1, arr.begin() + j);
        cout << arr[i + k - 2] << "\n";
    }
}