import sys
def is_possible(start):
    idx = start
    
    land_list = []
    while idx > 0:
        land_list.append(idx)
        idx = idx // 2
    idx = len(land_list) - 1
    while idx >= 0:
        if visited[land_list[idx]]:
            return land_list[idx]
        idx -= 1
    visited[start] = 1
    return 0

N, Q = map(int, input().split())
visited = [0] * (N + 1)
for i in range(Q):
    land = int(sys.stdin.readline())
    print(is_possible(land))