#include <iostream>

/* a,b,c,d */
int arr[52][52][52][52];
int a, b, c, d;

void cal()
{
    arr[2][2][1][1] = 3;
    for (int i = 3; i <= a; i++)
    {
        arr[i][2][i - 1][1] = arr[i - 1][2][i - 2][1] + 1;
        {
            for (int j = 3; j <= b; j++)
            {
                arr[i][j][i - 1][j - 1] = arr[i][j - 1][i - 1][j - 2] + 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d %d", &a, &b, &c, &d);
    cal();
}