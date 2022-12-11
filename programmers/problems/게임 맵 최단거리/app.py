from queue import Queue


def solution(maps):
    visited = [[0] * len(maps[0]) for i in range(len(maps))]
    max_x = len(maps[0])
    max_y = len(maps)
    q = Queue()

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    q.put({"x": 0, "y": 0})
    visited[0][0] = 1
    while not q.empty():
        now = q.get()
        bx = now["x"]
        by = now["y"]
        for i in range(4):
            nx = bx + dx[i]
            ny = by + dy[i]
            if nx >= 0 and nx < max_x and ny >= 0 and ny < max_y:
                if visited[ny][nx] == 0 and maps[ny][nx] == 1:
                    visited[ny][nx] = visited[by][bx] + 1
                    q.put({"x": nx, "y": ny})
    if not visited[max_y - 1][max_x - 1]:
        return -1
    return visited[max_y - 1][max_x - 1]
