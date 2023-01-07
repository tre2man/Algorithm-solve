def solution(rows, columns, queries):
    answer = []
    board = [[0] * columns for _ in range(rows)]
    # 배열 채우기
    n = 1
    for row in range(rows):
        for col in range(columns):
            board[row][col] = n
            n += 1
    for x1, y1, x2, y2 in queries:
        temp = board[x1-1][y1-1]
        min_num = temp
        # 쿼리 실행
        # 좌측
        for row in range(x1-1, x2-1):
            board[row][y1-1] = board[row+1][y1-1]
            min_num = min(min_num, board[row][y1-1])
        # 하단
        for col in range(y1-1, y2-1):
            board[x2-1][col] = board[x2-1][col+1]
            min_num = min(min_num, board[x2-1][col])
        # 우측
        for row in range(x2-1, x1-1, -1):
            board[row][y2-1] = board[row-1][y2-1]
            min_num = min(min_num, board[row][y2-1])
        # 상단
        for col in range(y2-1, y1-1, -1):
            board[x1-1][col] = board[x1-1][col-1]
            min_num = min(min_num, board[x1-1][col])
        board[x1-1][y1] = temp
        answer.append(min_num)
    return answer
