T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    total_price = list(map(int, input().split()))
    check_board = [0] * (2 * N)
    check_idx = 0
    check_insert_idx = 0
    print("Case #{}:".format(tc), end=" ")
    for idx in range(2 * N):
        temp = total_price[idx]
        if idx == 0:
            check_board[check_idx] = temp
            check_insert_idx += 1
            continue
        if temp == check_board[check_idx] * 4 // 3:
            print(check_board[check_idx], end=" ")
            check_idx += 1
        else:
            check_board[check_insert_idx] = temp
            check_insert_idx += 1
    print()