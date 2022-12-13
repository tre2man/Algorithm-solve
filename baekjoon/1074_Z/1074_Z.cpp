#include <iostream>
#include <math.h>
using namespace std;

/*
모든 곳을 탐색하지 않게 주의한다.
*/

int r, c, ans;

void find(int x, int y, int size)
{
    /*좌표를 찾았을 경우*/
    if (x == r && y == c)
    {
        cout << ans << endl;
        return;
    }
    /*해당 영역 내에 있을 경우*/
    if (r < x + size && r >= x && c < y + size && c >= y)
    {
        find(x, y, size / 2);
        find(x, y + size / 2, size / 2);
        find(x + size / 2, y, size / 2);
        find(x + size / 2, y + size / 2, size / 2); 
    }
    /*좌표를 찾지 못하였을 경우*/
    else
        ans += pow(size,2); 
}

int main()
{
    int N;

    cin >> N >> r >> c;
    ans = 0;
    find(0, 0, pow(2, N));
}