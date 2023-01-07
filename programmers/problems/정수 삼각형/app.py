def solution(triangle):
    # 한 개의 칸에 들어올 수 있는 경우의 수는 2가지이다.
    # 2가지 경우 중 큰 경우를 dp배열에 저장한다.
    # dp의 마지막 줄에서 가장 큰 값을 반환한다.
    dp = []
    for i in range(0, len(triangle)):
        now = []
        if i == 0:
            dp.append(triangle[i])
            continue
        for idx, j in enumerate(triangle[i]):
            if idx == 0:
                now.append(j + dp[i-1][0])
            elif idx == len(triangle[i]) - 1:
                now.append(j + dp[i-1][-1])
            else:
                now.append(j + max([dp[i-1][idx-1], dp[i-1][idx]]))
        dp.append(now)
    return max(dp[-1])
