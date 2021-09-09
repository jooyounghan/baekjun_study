N = int(input())
beads = list(map(int, input().split()))
used = [0] * 10

max_num = 0

def backtracking(temp_max, cnt):
    global max_num
    if cnt == N - 2:
        if max_num < temp_max:
            max_num = temp_max
        return
    
    for i in range(1, N - 1):
        if not used[i]:
            used[i] = 1
            left_idx = i - 1
            right_idx = i + 1
            while used[left_idx]:
                left_idx -= 1
            while used[right_idx]:
                right_idx += 1
            backtracking(temp_max + beads[left_idx] * beads[right_idx], cnt + 1)
            used[i] = 0
    return

backtracking(0, 0)
print(max_num)