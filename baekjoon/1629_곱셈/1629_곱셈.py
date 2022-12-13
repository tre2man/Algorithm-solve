# 분할 정복을 이용한 지수연산
# 지수가 짝수일 경우, 지수/2 * 지수/2 연산 반환
# 지수가 홀수일 경우, (지수-1)/2 * (지수-1)/2 * 밑 반환
a = b = c = 0


def cal_pow(base, exp):
    if exp == 0:
        return 1
    if exp == 1:
        return base % c
    # 지수가 홀수
    if exp % 2 == 0:
        temp = cal_pow(base, exp / 2)
        return (temp * temp) % c
    # 지수가 짝수
    else:
        temp = cal_pow(base, (exp - 1) / 2)
        return (temp * temp * base) % c


def main():
    global a, b, c
    a, b, c = map(int, input().split())
    print(cal_pow(a, b) % c)


main()
