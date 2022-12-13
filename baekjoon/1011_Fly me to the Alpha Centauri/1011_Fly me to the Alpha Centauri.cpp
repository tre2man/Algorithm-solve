#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*
미완성
*/

void cal(long n)
{
    long pow;

    pow = 1;
    while (pow * pow <= n)
        pow++;
    pow--;

    if (n == pow * pow)
    {
        printf("%ld\n", pow * 2 - 1);
        return;
    }
    else
    {

    }
}

int main()
{
    int t;
    long x, y;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%ld %ld\n", &x, &y);
        cal(abs(x - y));
    }
}