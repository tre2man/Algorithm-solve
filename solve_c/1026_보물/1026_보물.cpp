#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a,int b)
{
    return a > b;
}

int main()
{
    int num, temp, ans =0;
    vector<int> arrA;
    vector<int> arrB;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        arrA.push_back(temp);
    }  
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        arrB.push_back(temp);
    }
    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end(), comp);

    for (int i = 0; i < num; i++)
        ans += arrA.at(i) * arrB.at(i);

    printf("%d", ans);
    return 0;
}