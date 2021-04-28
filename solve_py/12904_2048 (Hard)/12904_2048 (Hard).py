import sys
from copy import deepcopy
from math import log2


'''
12100 2048(Hard)재탕
플이중...
이동했을 때 변화 없을경우 같은방향 탐색 안함
현재 뎁스에서 최대값에 도달할수 없는경우 가지치기
예)10번 이동시 최대값 1024
이전 뎁스에서 최대값 512 이하인경우
그 이전 뎁스에서 최대값 256 이하인경우
'''


# 재귀함수 호출 횟수 증가
sys.setrecursionlimit(100000)


ans = 0
visited = [0 for i in range(30)]


#위로 이동하기
def moveUp(N, arr, sumCount):
    ifSum = False ###
    temp = deepcopy(arr)
    for i in range(N):
        temparr = []
        for j in range(0, N):
            if temp[j][i] != 0:
                temparr.append(temp[j][i])
                temp[j][i] = 0
        while len(temparr) < N:
            temparr.append(0)
        for j in range(0, N):
            temp[j][i] = temparr[j]
        for j in range(0, N - 1):
            if temp[j][i] == temp[j + 1][i]:
                ifSum = True ###
                temp[j][i] *= 2
                for k in range(j + 1, N - 1):
                    temp[k][i] = temp[k + 1][i]
                temp[N - 1][i] = 0
    if ifSum:
        sumCount = 0
    else:
        sumCount += 1
    return temp, sumCount


#아래로 이동하기
def moveDown(N, arr, sumCount):
    ifSum = False ###
    temp = deepcopy(arr)
    for i in range(N):
        temparr = []
        for j in range(N - 1, -1, -1):
            if temp[j][i] != 0:
                temparr.append(temp[j][i])
                temp[j][i] = 0
        while len(temparr) < N:
            temparr.append(0)
        for j in range(N - 1, -1, -1):
            temp[j][i] = temparr[N - 1 - j]
        for j in range(N - 1, 0, -1):
            if temp[j][i] == temp[j - 1][i]:
                ifSum = True ###
                temp[j][i] *= 2
                for k in range(j - 1, 0, -1):
                    temp[k][i] = temp[k - 1][i]
                temp[0][i] = 0
    if ifSum:
        sumCount = 0
    else:
        sumCount += 1
    return temp, sumCount


# 우측으로 이동하기
def moveRight(N, arr, sumCount):
    ifSum = False ###
    temp = deepcopy(arr)
    for i in range(N):
        cnt = temp[i].count(0)
        temp[i] = [item for item in temp[i] if item != 0]
        for j in range(cnt):
            temp[i].insert(0, 0)
        for j in range(N - 1, 0, -1):
            if temp[i][j] == temp[i][j-1]:
                ifSum = True ###
                temp[i][j] *= 2
                temp[i].pop(j-1)
                temp[i].insert(0, 0)
    if ifSum:
        sumCount = 0
    else:
        sumCount += 1
    return temp, sumCount


#좌측으로 이동하기
def moveLeft(N, arr, sumCount):
    ifSum = False ###
    temp = deepcopy(arr)
    for i in range(N):
        cnt = temp[i].count(0)
        temp[i] = [item for item in temp[i] if item != 0]
        for j in range(cnt):
            temp[i].append(0)
        for j in range(0, N - 1):
            if temp[i][j] == temp[i][j + 1]:
                ifSum = True ###
                temp[i][j] *= 2
                temp[i].pop(j + 1)
                temp[i].append(0)
    if ifSum:
        sumCount = 0
    else:
        sumCount += 1
    return temp, sumCount


# 모든 경우의 수에 대해서 탐색하기
def backTrack(count, N, arr, sumCount):
    global ans
    if count == 10:
        ans = max(ans, max(map(max, arr)))
    else:
        temparr, tempcount = moveUp(N, arr, sumCount)
        if tempcount != 1:
            backTrack(count + 1, N, temparr, tempcount)
        temparr, tempcount = moveDown(N, arr, sumCount)
        if tempcount != 1:
            backTrack(count + 1, N, temparr, tempcount)
        temparr, tempcount = moveLeft(N, arr, sumCount)
        if tempcount != 1:
            backTrack(count + 1, N, temparr, tempcount)
        temparr, tempcount = moveRight(N, arr, sumCount)
        if tempcount != 1:
            backTrack(count + 1, N, temparr, tempcount)


def main():
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    backTrack(0, N, arr, 0)
    print(ans)


main()
