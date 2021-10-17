from collections import deque
from sys import stdin
input = stdin.readline

def bfs(start):
    global cnt
    check = deque()
    check.append(start)
    visited[start] = 1
    flag = True
    while check:
        flag = True
        check_node = check.popleft()
        for adj_node in adj[check_node]:
            if visited[adj_node] == 0:
                visited[adj_node] = visited[check_node] + 1
                check.append(adj_node)
                flag = False
        if flag:
            cnt += visited[check_node] - 1

N = int(input())
adj = [[] for _ in range(N + 1)]
visited = [0] * (N + 1)
for i in range(N - 1):
    temp1, temp2 = map(int, input().split())
    adj[temp1].append(temp2)
    adj[temp2].append(temp1)
cnt = 0
bfs(1)
if cnt % 2:
    print("Yes")
else:
    print("No")
