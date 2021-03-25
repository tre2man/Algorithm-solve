#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool comp(string a, string b)
{
    if (a.length() != b.length())
        return (a.length() < b.length());
    else
        return (a < b);
}

int main()
{
    vector<string> v;
    string a;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < N - 1; i++)
        if (v[i].compare(v[i + 1]))
            cout << v[i] << endl;
    cout << v[N - 1] << endl;
    return (0);
}
