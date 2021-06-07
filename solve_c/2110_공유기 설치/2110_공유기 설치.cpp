#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int check(int length)
{
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, C, temp, maxempty = 0;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++)
		maxempty = max(maxempty, v[i + 1] - v[i]);
	
}