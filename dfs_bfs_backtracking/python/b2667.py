def dfs(house_map, N):
    num_area = 0
    num_houses = []
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for row in range(N):
        for col in range(N):
            if house_map[row][col] == '1':
                temp_num = 0
                num_area += 1
                check_stack = [(row, col)]
                house_map[row][col] = '0'
                while check_stack:
                    temp_num += 1
                    check_row, check_col = check_stack.pop()
                    for direction in directions:
                        new_row = check_row + direction[0]
                        new_col = check_col + direction[1]
                        if 0 <= new_row < N and 0 <= new_col < N and house_map[new_row][new_col] == '1':
                            check_stack.append((new_row, new_col))
                            house_map[new_row][new_col] = '0'
                num_houses.append(temp_num)    
    num_houses.sort()
    print(num_area)
    for num_house in num_houses:
        print(num_house)

N = int(input())
house_map = [list(input()) for _ in range(N)]
dfs(house_map, N)
