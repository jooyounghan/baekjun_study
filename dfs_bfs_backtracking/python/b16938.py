from sys import stdin
input = stdin.readline

def backtracking(pos, temp_min, temp_max, temp_sum):
    global cnt
    if pos == N:
        if temp_sum >= L and temp_sum <= R and temp_max - temp_min >= X:
            cnt += 1
        return
    
    if temp_sum > R:
        return

    backtracking(pos + 1, min(temp_min, problems[pos]), max(temp_max, problems[pos]), temp_sum + problems[pos])
    backtracking(pos + 1, temp_min, temp_max, temp_sum)
    return

N, L, R, X = map(int, input().split())
problems = list(map(int, input().split()))
cnt = 0

backtracking(0, 10E6, 0, 0)
print(cnt)