min_value = 10000000

N = int(input())
visited = [0] * N
prices = [list(map(int, input().split())) for _ in range(N)]


def backtracking(cnt, pos, target, temp_val):
    global min_value
    if cnt == N:
        if prices[pos][target]:
            if temp_val + prices[pos][target] < min_value:
                min_value = temp_val + prices[pos][target]
        return
    
    if temp_val > min_value:
        return
    
    for i in range(N):
        if prices[pos][i] and not visited[i]:
            visited[i] = 1
            backtracking(cnt + 1, i, target, temp_val + prices[pos][i])
            visited[i] = 0
    return

for i in range(N):
    visited[i] = 1
    backtracking(1, i, i, 0)
    visited[i] = 0

print(min_value)