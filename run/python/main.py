
def solution(x, y):
    answer = -1
    xArr = []
    yArr = []
    # 가로줄 중 가장 큰 길이 + y좌표 구하기
    # y좌표 * 가로길이 중 가장 긴거 -> 나누기2
    for i in range(len(x)):
        horMax = 0
        ys = 0
        for j in range(len(y)):
            if y[i] == y[j] and horMax < abs(x[i] - x[j]):
                horMax = abs(x[i] - x[j])
                # print(i, j, horMax)
                ys = y[j]
        if horMax != 0:
            xArr.append(horMax)
            yArr.append(ys)
    for i in range(len(xArr)):
        for j in range(len(xArr)):
            if i != j and yArr[i] != yArr[j]:
                answer = max(answer, (xArr[i] + xArr[j])
                             * abs(yArr[i] - yArr[j]))
    return answer


if __name__ == "__main__":
    datas = [
        {
            "x": [2, 3, 4, 4, 7, 6, 3, 9, 9, 6, 5, 8, 6, 4],
            "y": [5, 9, 5, 1, 3, 1, 3, 3, 8, 7, 10, 9, 9, 8]
        },
    ]
    for data in datas:
        print(solution(data["x"], data["y"]))
