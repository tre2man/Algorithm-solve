def solution(numbers):
    answer = ''
    newNumbers = []
    for num in numbers:
        newNumbers.append(str(num))
    newNumbers.sort(reverse=True, key=lambda x: x * 3)
    answer += str(int("".join(newNumbers)))
    return answer
