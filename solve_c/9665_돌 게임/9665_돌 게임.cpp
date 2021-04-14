#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int arr[1001];

    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 1;
    for (int i = 4; i <= n; i++)
        arr[i] = min(arr[i - 1], arr[i - 3]) + 1;
    if (arr[n] % 2)
        cout << "SK";
    else
        cout << "CY";
    return (0);
}