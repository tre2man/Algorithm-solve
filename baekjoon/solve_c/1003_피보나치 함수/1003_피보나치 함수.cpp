#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*dp 이용하여 규칙 찾기. 0,1,1,2,3... 순서대로 호출하고 예외 처리 해준다.*/

void cal(int n)
{
    int arr[40];

    if (n == 0)
        printf("1 0");
    else if (n == 1)
        printf("0 1");
    else
    {
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i <= n; i++)
            arr[i] = arr[i - 2] + arr[i - 1];
        printf("%d %d", arr[n - 1], arr[n]);
    }
    printf("\n");
}

int main()
{
    int n, test;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &test);
        cal(test);
    }
    return (0);
}