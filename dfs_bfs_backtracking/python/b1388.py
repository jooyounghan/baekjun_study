def check_tile(floor_status, row, col):
    N = len(floor_status)
    M = len(floor_status[0])
    if floor_status[row][col] == "-":
        for c in range(col, M):
            if floor_status[row][col] != floor_status[row][c]:
                break
            visited[row][c] = 1
    if floor_status[row][col] == "|":
        for r in range(row, N):
            if floor_status[row][col] != floor_status[r][col]:
                break
            visited[r][col] = 1

N, M = map(int, input().split())

floor_status = [list(input()) for _ in range(N)]
visited = [[0] * M for _ in range(N)]

cnt = 0
for row in range(N):
    for col in range(M):
        if not visited[row][col]:
            cnt += 1
            check_tile(floor_status, row, col)

print(cnt)