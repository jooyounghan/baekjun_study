from sys import stdin
M, N = map(int, stdin.readline().split())

tomatoes = [list(map(int, stdin.readline().split())) for _ in range(N)]
result = 1

front = -1
rear = -1
queue = [0] * (1000 * 1000)

cnt = 0

for i in range(N):
    for j in range(M):
        if tomatoes[i][j] == 1:
            rear += 1
            queue[rear] = i * M + j
        elif tomatoes[i][j] == -1:
            cnt += 1

directions = ((1, 0), (-1, 0), (0, 1), (0, -1))


while front != rear:
    cnt += 1
    front += 1
    row = queue[front] // M
    col = queue[front] % M
    for direction in directions:
        new_row = row + direction[0]
        new_col = col + direction[1]
        if 0 <= new_row < N and 0 <= new_col < M and not tomatoes[new_row][new_col]:
            rear += 1
            queue[rear] = new_row * M + new_col
            tomatoes[new_row][new_col] = tomatoes[row][col] + 1
            result = tomatoes[new_row][new_col] if tomatoes[new_row][new_col] > result else result


if cnt == (N * M):
    print(result - 1)
else:
    print(-1)