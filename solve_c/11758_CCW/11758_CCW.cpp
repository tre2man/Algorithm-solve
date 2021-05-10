#include <iostream>
using namespace std;

/*
문제 풀이에 정신이 아찔해지고 가슴이 웅장해진다.
좌표 3개를 이용하여 삼각형 넓이 구하는 공식을 사용하자.
좌표 3개로 외적을 구할 수 있을 것이다. 
자세한 방법은 구글링하세요.
https://www.acmicpc.net/blog/view/27
*/

int main()
{
    double x1, y1, x2, y2, x3, y3, ccw;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ccw = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
    if (ccw > 0)
        cout << 1;
    else if (ccw < 0)
        cout << -1;
    else
        cout << 0;
    return (0);
}