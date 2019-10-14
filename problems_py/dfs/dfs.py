def safe(x,y):
    return x>=0 and y>=0 and x < N and y < M

def bfs():
        global arr, visited, day, q, front, rear

        while (front != rear):

            front += 1
            x1 = q[front][0]
            y1 = q[front][1]
            dx = [0,0,1,-1]
            dy = [1,-1,0,0]

            for i in range(4):
                nx = x1 + dx[i]
                ny = y1 + dy[i]
                if safe(nx,ny) and visited[nx][ny] ==0 and arr[nx][ny] ==0:
                    arr[nx][ny] = 1
                    visited[nx][ny] = 1 + visited[x1][y1]
                    day = visited[nx][ny]
                    rear += 1
                    q[rear] = (nx,ny)


M, N = map(int,input().split()) # 가로 , 세로

arr = [list(map(int,input().split())) for i in range(N)]
visited = [[0]*M for i in range(N)]

day = 0
q = [0]*N*M
rear = -1
front = -1
re = 0
for i in range(N):
    for j in range(M):
        if arr[i][j] == 1 :
            rear += 1
            q[rear] = (i,j)
            visited[i][j] = 1
for i in range(N):
    for j in range(M):
        if arr[i][j] != 1 :
            re = 1
bfs()
for i in range(N):
    for j in range(M):
        if arr[i][j] == 0 :
            day = 0


if re != 0:
    re = day-1

print(re)