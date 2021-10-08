from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
maps = [list(map(int, list(input())[:-1])) for _ in range(N)]
visited = [[[0,0] for _ in range(M)] for __ in range(N)]
values = [[0 for _ in range(M)] for __ in range(N)]

directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

def bfs():
    front = -1
    rear = 0
    check = [0] * (2 * N * M)

    check[rear] = [0, 0, 0]
    visited[0][0][0] = 1
    visited[0][0][1] = 1
    values[0][0] = 1

    while front < rear:
        front += 1
        row, col, work = check[front]
        for direction in directions:
            new_row = direction[0] + row
            new_col = direction[1] + col

            if 0 <= new_row < N and 0 <= new_col < M:
                if maps[new_row][new_col] == 1:
                    if work == 0 and visited[new_row][new_col][1] == 0:
                        visited[new_row][new_col][1] = 1
                        values[new_row][new_col] = values[row][col] + 1
                        rear += 1
                        check[rear] = [new_row, new_col, 1]
                else:
                    if visited[new_row][new_col][work] == 0:
                        visited[new_row][new_col][work] = 1
                        values[new_row][new_col] = values[row][col] + 1
                        rear += 1
                        check[rear] = [new_row, new_col, work]
            if new_row == N - 1 and new_col == M - 1:
                return

bfs()

if values[N - 1][M - 1] == 0:
    values[N - 1][M - 1] = -1
print(values[N - 1][M - 1])