
from queue import Queue


def bfs(n, computers, com, visited):
    visited[com] = True
    q = Queue()
    q.put(com)
    while not q.empty():
        com = q.get()
        visited[com] = True
        for connect in range(n):
            if connect != com and computers[com][connect] == 1:
                if visited[connect] == False:
                    q.put(connect)


def solution(n, computers):
    answer = 0  # network
    visited = [False for i in range(n)]
    for com in range(n):
        if visited[com] == False:
            bfs(n, computers, com, visited)
            answer += 1
    return answer
