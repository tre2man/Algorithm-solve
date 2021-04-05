# 지수 연산을 하는 함수
def cal_pow(base, exp):
    if exp == 0:
        return 1
    if exp == 1:
        return base
    # 지수가 홀수
    if exp % 2 == 0:
        temp = cal_pow(base, exp / 2)
        return temp * temp
    # 지수가 짝수
    else:
        temp = cal_pow(base, (exp - 1) / 2)
        return temp * temp * base


def fibo(a):
    if a == 1:
        return 1
    if a == 2:
        return 1
    if a == 3:
        return 2
    if a % 2 == 0:
        n = fibo(a // 2) % 1000000
        nn = fibo(a // 2 - 1) % 1000000
        return (2 * n * nn % 1000000 + n * n % 1000000) % 1000000
    else:
        n = fibo(a // 2 + 1) % 1000000
        nn = fibo(a // 2) % 1000000
        return (n ** 2 % 1000000 + nn ** 2 % 1000000) % 1000000


def main():
    a = int(input())
    print(fibo(a))


main()