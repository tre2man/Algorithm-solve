#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*겹치는 점이 0, 1, 2, 무한대일 경우에 대하여 생각한다.*/

int main()
{
    int n;
    double arr[6];
    double location_len;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
            scanf("%lf", &arr[j]);
        location_len = sqrt(pow(arr[0] - arr[3], 2) + pow(arr[1] - arr[4], 2));
        if (arr[0] == arr[3] && arr[1] == arr[4] && arr[2] == arr[5])
            printf("-1");
        else if ((location_len < abs(arr[2] - arr[5])) || (location_len > arr[2] + arr[5]))
            printf("0");
        else if (location_len == arr[2] + arr[5] || location_len == abs(arr[2] - arr[5]))
            printf("1");
        else
            printf("2");
        printf("\n");
    }
    return (0);
}
