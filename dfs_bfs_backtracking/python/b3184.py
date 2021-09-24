from sys import stdin

R, C = map(int, input().split())

def dfs(row, col):
    global visited
    temp_sheep = temp_wolves = 0
    directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    stacks = [[row, col]]
    visited[row][col] = 1
    while stacks:
        check = stacks.pop()
        if fields[check[0]][check[1]] == 'v':
            temp_wolves += 1
        if fields[check[0]][check[1]] == 'o':
            temp_sheep += 1

        for direction in directions:
            temp_row = check[0] + direction[0]
            temp_col = check[1] + direction[1]
            if temp_row >= 0 and temp_row < R and temp_col >= 0 and temp_col < C and not visited[temp_row][temp_col] and fields[temp_row][temp_col] != "#":
                visited[temp_row][temp_col] = 1
                stacks.append([temp_row, temp_col])
    return temp_sheep, temp_wolves

fields = [stdin.readline() for _ in range(R)]
visited = [[0 for _ in range(C)] for __ in range(R)]

sheep = wolves = 0

for row in range(R):
    for col in range(C):
        if fields[row][col] == "." or fields[row][col] == "v" or fields[row][col] == "o":
            if not visited[row][col]:
                temp_sheep, temp_wolves = dfs(row, col)
                temp_sheep = temp_sheep if temp_sheep > temp_wolves else 0
                temp_wolves = 0 if temp_sheep > temp_wolves else temp_wolves
                sheep += temp_sheep
                wolves += temp_wolves

print("{} {}".format(sheep, wolves))