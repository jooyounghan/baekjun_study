N = int(input())
connects = int(input())
connections = [[] for _ in range(N + 1)]


def DFS(connections, N):
    cnt = 0
    visited = [0] * (N + 1)
    check_stack = [1]
    visited[1] = 1
    while check_stack:
        cnt += 1
        temp_node = check_stack.pop()
        for other in connections[temp_node]:
            if not visited[other]:
                check_stack.append(other)
                visited[other] = 1
    return cnt - 1


for i in range(connects) :
    start, end = map(int, input().split())
    connections[start].append(end)
    connections[end].append(start)
print(DFS(connections, N))