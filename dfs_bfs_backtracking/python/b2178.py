from sys import stdin

N, M = map(int, input().split())

fields = [list(map(int, list(stdin.readline())[:-1])) for _ in range(N)]

front = -1
rear = 0
queue = [0] * (100 * 100)
queue[rear] = 0

directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

while front != rear:
    front += 1
    row = queue[front] // M
    col = queue[front] % M
    if row == N - 1 and col == M - 1:
        print(fields[row][col])
        break

    for direction in directions:
        new_row = row + direction[0]
        new_col = col + direction[1]
        if 0 <= new_row < N and 0 <= new_col < M and fields[new_row][new_col] == 1:
            if new_row == 0 and new_col == 0:
                continue
            rear += 1
            queue[rear] = new_row * M + new_col
            fields[new_row][new_col] = fields[row][col] + 1
