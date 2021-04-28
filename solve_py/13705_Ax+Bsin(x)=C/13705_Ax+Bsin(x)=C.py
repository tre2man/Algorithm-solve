from decimal import *


getcontext().prec = 50


pi = Decimal('3.141592653589793238462643383279502884197169399375')


def customSin(x):
    if x > pi:
        while x > pi:
            x -= 2 * pi
    elif x < -pi:
        while x < pi:
            x += 2 * pi
    i, last, now, fact, num, sign = 1, 0, x, 1, x, 1
    while now != last:
        last = now
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        now += num / fact * sign
    return +now


def isPositive(a, b, c, x):
    if a * Decimal(x) + b * Decimal(customSin(Decimal(x))) - c > 0:
        return True
    else:
        return False


def calBisection(a, b, c):
    xLeft = c / a - Decimal('1')
    xRight = c / a + Decimal('1')
    while xRight - xLeft > Decimal(1e-20):
        temp = (xLeft + xRight) / 2
        if isPositive(a, b, c, temp):
            xRight = temp
        else:
            xLeft = temp
    print(round((xRight + xLeft) / 2, 6))


def main():
    a, b, c = map(Decimal, input().split())
    calBisection(a, b, c)


main()
