def backtracking(cnt, rest):
    global possible
    if cnt == N:
        possible += 1
        return
    
    for i in range(N):
        if used[i] == 0 and rest + weights[i] - K >= 0:
            used[i] = 1
            backtracking(cnt + 1, rest + weights[i] - K)
            used[i] = 0

N, K = map(int, input().split())
weights = list(map(int, input().split()))
used = [0] * N
possible = 0
backtracking(0, 0)
print(possible)