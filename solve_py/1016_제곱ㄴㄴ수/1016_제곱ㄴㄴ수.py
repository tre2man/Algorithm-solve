import math


def main():
    ans = 0
    min_num, max_num = map(int, input().split())
    non_numbers = [1 for _ in range((max_num - min_num) + 1)]
    numbers = []
    # 제곱수 저장하기
    for i in range(2, int(math.sqrt(max_num)) + 1):
        numbers.append(i*i)

    #모든 제곱수에 대하여
    for i in numbers:
        #제곱수의 배수 중 i*j>=min 만족하는 수
        j = math.ceil(min_num / i)
        # b까지 제곱수 찾아서 non_numbers 수정하기
        while i * j <= max_num:
            non_numbers[i * j - min_num] = 0
            j += 1
    #1이 들어간 곳은 조건을 만족하는 곳
    print(sum(non_numbers))


main()
