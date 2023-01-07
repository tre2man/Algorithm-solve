import heapq


def solution(jobs):
    ans, now, idx = 0, 0, 0
    start = -1
    heap = []

    while idx < len(jobs):
        for j in jobs:
            if start < j[0] <= now:  # 현재시점에서 처리할 수 있는 작업인지를 판별
                heapq.heappush(heap, [j[1], j[0]])
        if len(heap) > 0:  # 힙에 작업이 있을 경우
            current = heapq.heappop(heap)
            start = now
            now += current[0]
            ans += (now - current[1])
            idx += 1
        else:  # 처리할 수 있는 작업이 없다면? 현재 시점 올리기
            now += 1
    return int(ans / len(jobs))
