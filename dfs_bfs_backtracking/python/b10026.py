N = int(input())
pictures = [input() for _ in range(N)]
visited = [[False for _ in range(N)] for __ in range(N)]
directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def check(i, j, blind_checked):
    front = -1
    rear = 0
    queue = [0] * (N * N)

    queue[rear] = (i, j)
    visited[i][j] = not blind_checked

    cmpchar = pictures[i][j]

    while front != rear:
        front += 1
        row, col = queue[front]
        for direction in directions:
            new_row = row + direction[0]
            new_col = col + direction[1]
            add_flag = False
            if 0 <= new_row < N and 0 <= new_col < N and visited[new_row][new_col] == blind_checked:
                if blind_checked:
                    if cmpchar == 'B' and pictures[new_row][new_col] == 'B':
                        add_flag = True
                    if cmpchar != 'B' and pictures[new_row][new_col] != 'B':
                        add_flag = True
                else:
                    if cmpchar == pictures[new_row][new_col]:
                        add_flag = True
            if add_flag:
                visited[new_row][new_col] = not blind_checked
                rear += 1
                queue[rear] = (new_row, new_col)

group_num = group_blind_num = 0

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            check(i, j, False)
            group_num += 1

for i in range(N):
    for j in range(N):
        if  visited[i][j]:
            check(i, j, True)
            group_blind_num += 1

print(group_num, group_blind_num)
