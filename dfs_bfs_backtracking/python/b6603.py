visited = [0] * 13

def backtracking(pos, cnt):
    if cnt == 6:
        for i in range(13):
            if visited[i]:
                print(lottos[i], end=' ')
        print()
        return

    if pos >= k:
        return

    visited[pos] = 1
    backtracking(pos + 1, cnt + 1)
    visited[pos] = 0
    backtracking(pos + 1, cnt)
    return


times = 0
while True:
    lottos = list(map(int, input().split()))
    k = lottos.pop(0)
    if not k:
        break
    if times:
        print()
    times += 1
    backtracking(0, 0)
