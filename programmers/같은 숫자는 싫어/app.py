def solution(arr):
    answer = []
    for num in arr:
        if len(answer) == 0 or answer[len(answer) - 1] != num:
            answer.append(num)
    return answer
