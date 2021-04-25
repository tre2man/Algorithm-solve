from itertools import combinations
from copy import deepcopy


N = M = 0
ans = 99999999
locChicken = []
locCheck = []
locHouse = []
arr = []


def checkClength(in_x, in_y, checkArr):
    global N, arr, locChicken
    temp = 9999999
    for i in locChicken:
        if checkArr[i[0]][i[1]] == 2:
            temp = min(temp, abs(in_x - i[0]) + abs(in_y - i[1]))
    return temp


def exploreClength():
    global ans, arr, locCheck, locChicken, temp
    for a in locCheck:
        temp = deepcopy(arr)
        for b in a:
            temp[locChicken[b][0]][locChicken[b][1]] = 0
        sumLength = 0
        for i in range(len(temp)):
            for j in range(len(temp[i])):
                if temp[i][j] == 1:
                    sumLength += checkClength(i, j, temp)
        ans = min(ans, sumLength)


def main():
    global N, M, ans, locChicken, locCheck, arr, locHouse
    N, M = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(N)]
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == 2:
                locChicken.append([i, j])
    # 지워야 하는 곳의 좌표 인덱스를 기록한 배열
    locCheck = list(combinations(
        list(range(len(locChicken))), len(locChicken) - M))
    exploreClength()
    print(ans)


main()