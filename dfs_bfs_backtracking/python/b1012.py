import sys
input = sys.stdin.readline

directions = ((1, 0), (-1, 0), (0, 1), (0, -1))

def bfs(row, col):
    front = -1
    rear = 0
    queue = [0] * (R * C)
    queue[rear] = (row, col)
    maps[row][col] = False

    while front < rear:
        front += 1
        temp_r, temp_c = queue[front]
        for direction in directions:
            new_r = temp_r + direction[0]
            new_c = temp_c + direction[1]
            if 0 <= new_r < R and 0 <= new_c < C:
                if maps[new_r][new_c] == True:
                    maps[new_r][new_c] = False
                    rear += 1
                    queue[rear] = (new_r, new_c)
    return

T = int(input())
for tc in range(T):
    C, R, K = map(int, input().split())
    maps = [[False for _ in range(C)] for _ in range(R)]
    
    check = [0] * K
    for idx in range(K):
        c, r = map(int, input().split())
        maps[r][c] = True
        check[idx] = [r, c]
    cnt = 0
    for idx in range(K):
        if maps[check[idx][0]][check[idx][1]] == True:
            cnt += 1
            bfs(check[idx][0], check[idx][1])

    print(cnt)
