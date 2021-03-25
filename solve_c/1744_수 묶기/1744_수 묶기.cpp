#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
dp 형식의 문제로 접근하자.
N==1,2 일 경우에는 따로 예외처리 
n번째 숫자는 답안의 n-2와 입력의 n-1, n번째 수를 비교하여 판별함.
*/

int N, temp;
int arr[10000][2];
vector<int> ans;

void sort()
{
    int temp;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {
                temp = arr[j][0];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = temp;
            }
        }
    }
}

int cal(int x, int y, int i)
{
    if (x * y > x + y)
    {
        arr[i][1] = 1;
        return (x * y);
    }
    else
        return (x + y);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i][0]);
        arr[i][1] = 0;
    }
    sort();
    if (N == 1)
    {
        printf("%d\n", arr[0][0]);
        return (0);
    }
    if (N == 2)
    {
        printf("%d\n", cal(arr[0][0], arr[1][0], 0));
        return (0);
    }
    else
    {
        ans.push_back(arr[0][0]);
        ans.push_back(cal(arr[0][0], arr[1][0], 1));
        for (int i = 2; i < N; i++)
        {
            /* 곱한 경우일 때 */
            if (arr[i - 1][1] == 1)
            {
                ans.push_back(max(ans[i - 2] + cal(arr[i - 1][0], arr[i][0], i), ans[i - 1] + arr[i][0]));
            }
            /* 곱하지 않았을 때 */
            else
            {
                if (ans[i - 2] + cal(arr[i - 1][0], arr[i][0], i) > ans[i - 1] + arr[i][0])
                {
                    ans.push_back(max(ans[i - 2] + cal(arr[i - 1][0], arr[i][0], i), ans[i - 1] + arr[i][0]));
                }
                else
                {
                    ans.push_back(max(ans[i - 2] + cal(arr[i - 1][0], arr[i][0], i), ans[i - 1] + arr[i][0]));
                    arr[i][1] = 0;
                }
            }
        }
    }
    printf("%d\n", ans.back());
    return (0);
}