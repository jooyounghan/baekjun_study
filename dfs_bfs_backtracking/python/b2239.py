def check_row_col(row, col, cmp):
    for k in range(9):
        if sudoku[row][k] == cmp or sudoku[k][col] == cmp:
            return False
    return True

def check_small_box(row, col, cmp):
    for r in range(3 * (row // 3), 3 * (row // 3) + 3):
        for c in range(3 * (col // 3), 3 * (col // 3) + 3):
            if sudoku[r][c] == cmp:
                return False
    return True
    
def backtracking(front, rear):
    global sudoku
    if rear == front:
        for r in range(R):
            print(*sudoku[r], sep = "")
        exit()
    
    new_row, new_col = check_queue[front + 1]
    for i in range(1, 10):
        if check_small_box(new_row, new_col, i) and check_row_col(new_row, new_col, i):
            sudoku[new_row][new_col] = i
            backtracking(front + 1, rear)
            sudoku[new_row][new_col] = 0
    return
####################################################################

R, C = (9, 9)

sudoku = [list(map(int, input())) for _ in range(R)]
front = -1
rear = -1
check_queue = [[0, 0] for _ in range(81)] 

for r in range(9):
    for c in range(9):
        if sudoku[r][c] == 0:
            rear += 1
            check_queue[rear][0] = r
            check_queue[rear][1] = c

backtracking(front, rear)