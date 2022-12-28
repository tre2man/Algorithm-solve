import heapq
import math


class Solution:
    def minStoneSum(self, piles: list[int], k: int) -> int:
        hq = []
        for pile in piles:
            heapq.heappush(hq, -pile)
        print(hq)
        while k > 0:
            pop = heapq.heappop(hq)
            heapq.heappush(hq, math.floor(pop / 2))
            print(hq)
            k -= 1
        return -sum(hq)
