#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
백트래킹을 이용하여 풀 수 있는 간단한 문제이다.
반복문의 시작점을 start, M이 될때까지 반복
재귀 함수를 부를 때 count + 1을 한다.
*/

vector<int> input;
int arr[8];
int visited[8];
int M, N, temp;

void print()
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void back(int start, int count)
{
    if (count == N)
    {
        print();
        return;
    }
    for (int i = start; i < M; i++)
    {
        if (!visited[i])
        {
            arr[count] = input[i];
            visited[i] = 1;
            back(start, count + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }
    sort(input.begin(), input.end());
    back(0, 0);
    return (0);
}