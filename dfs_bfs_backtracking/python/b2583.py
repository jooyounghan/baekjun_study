def dfs(square, row, col):
    result_num = 0
    result_area = []

    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    for r in range(row):
        for c in range(col):
            if not square[r][c]:
                result_num += 1
                check_stack = [(r,c)]
                square[r][c] = 1
                temp_num = 0
                while check_stack:
                    temp_num += 1
                    check = check_stack.pop()
                    for direction in directions:
                        new_row = check[0] + direction[0]
                        new_col = check[1] + direction[1]
                        if 0 <= new_row < row and 0 <= new_col < col and not square[new_row][new_col]:
                            check_stack.append((new_row, new_col))
                            square[new_row][new_col] = 1
                result_area.append(temp_num)
    result_area.sort()
    print(result_num)
    print(*result_area)

row, col, k = map(int, input().split())
square = [[0] * col for _ in range(row)]

for i in range(k):
    l_col, l_row, r_col, r_row = map(int, input().split())
    for r in range(l_row, r_row):
        for c in range(l_col, r_col):
            square[r][c] = 1
dfs(square, row, col)