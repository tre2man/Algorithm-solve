arr = [0 for i in range(0, 10001)]


def fibo(a):
    index = 3
    arr[1] = 1
    arr[2] = 1
    while index <= a:
        arr[index] = arr[index - 1] + arr[index - 2]
        index += 1
    return arr[a]


def main():
    a = int(input())
    print(fibo(a))


main()
