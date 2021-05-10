#include <iostream>
using namespace std;

/*
피보나치 정의를 그대로 가져옴.
나중에 이해하는 과정 피요
*/

#define MOD 1000000

typedef long long ll;
typedef struct matrix
{
    ll arr[2][2];
} matrix;

/* 1번째 배열로 초기화 */
void init_arr(matrix *input)
{
    input->arr[0][0] = 1;
    input->arr[0][1] = 1;
    input->arr[1][0] = 1;
    input->arr[1][1] = 0;
}

matrix mul_arr(matrix a, matrix b)
{
    matrix c;
    c.arr[0][0] = (a.arr[0][0] * b.arr[0][0] + a.arr[0][1] * b.arr[1][0]) % MOD;
    c.arr[0][1] = (a.arr[0][0] * b.arr[1][0] + a.arr[0][1] * b.arr[1][1]) % MOD;
    c.arr[1][0] = (a.arr[1][0] * b.arr[0][0] + a.arr[1][1] * b.arr[1][0]) % MOD;
    c.arr[1][1] = (a.arr[1][0] * b.arr[1][0] + a.arr[1][1] * b.arr[1][1]) % MOD;
    return (c);
}

matrix pow_matrix(matrix a, ll n)
{
    if (n > 1)
    {
        a = pow_matrix(a, n / 2);
        a = mul_arr(a, a);
        if (n & 1)
        {
            matrix b;
            init_arr(&b);
            a = mul_arr(a, b);
        }
    }
    return (a);
}

ll fibo(ll n)
{
    matrix a;
    init_arr(&a);
    a = pow_matrix(a, n);
    return (a.arr[0][1]);
}

int main()
{
    ll a;
    cin >> a;
    cout << fibo(a);
    return (0);
}