directions = ((1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1))

def bfs(row, col):
    visited[row][col] = True

    front = -1
    rear = 0
    queue = [0] * (W * H)
    queue[rear] = [row, col]

    while front < rear:
        front += 1
        temp_row, temp_col = queue[front]
        for direction in directions:
            new_row = temp_row + direction[0]
            new_col = temp_col + direction[1]
            if 0 <= new_row < H and 0 <= new_col < W:
                if not visited[new_row][new_col] and lands[new_row][new_col]:
                    visited[new_row][new_col] = True
                    rear += 1
                    queue[rear] = [new_row, new_col]
    return

while True:
    W, H = map(int, input().split())
    if W == 0 and H == 0:
        break

    lands = [list(map(int, input().split())) for _ in range(H)]
    visited = [[False for _ in range(W)] for __ in range(H)]
    cnt = 0
    for i in range(H):
        for j in range(W):
            if not visited[i][j] and lands[i][j]:
                cnt += 1
                bfs(i, j)
    
    print(cnt)
