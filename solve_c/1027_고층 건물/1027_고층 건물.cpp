#include <iostream>
#include <cmath>

/*
제작중
*/

double building[51];
double a, b;
int N, ans = 0;

void make_ab(double x1, double y1, double x2, double y2)
{
    a = (y2 - y1) / (x2 - x1);
    b = y1 - (x1 * (y2 - y1)) / (x2 - x1);
}

void cal()
{
    for (int i = 0; i < N; i++)
    {
        int left_coun = rigth_count = 0;
        /* 왼쪽 방향 탐색 */
        for (int j = i - 1; j >= 0; j--)
        {
            if (j == 0)
                left_count = 0;
            else
                left_count = 1;
            make_ab((double)i, building[i], (double)j, building[j]);
            for (int k = i - 1; k >= 0; k--)
            {
                double res = a * k + b;
                if (floor(res + 0.5) > floor(building[k] + 0.5))
                    count++;
                else if (res < 0 || res > 1000000001)
                    break;
            }
        }
        /* 오른쪽 방향 탐색 */
        for (int j = i + 1; j < N; j++)
        {
            make_ab((double)i, building[i], (double)j, building[j]);
            for (int k = i + 1; k < N; k++)
            {
                if (j == N - 1)
                    right_count = 0;
                else   
                    right_count = 1;
                double res = a * k + b;
                //printf("%lf\n", res);
                if (floor(res + 0.5) > floor(building[k] + 0.5))
                    count++;
                else if (res < 0 || res > 1000000001)
                    break;
            }
        }
        if (count > ans)
            ans = count;
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lf", &building[i]);
    cal();
    printf("%d", ans);
}