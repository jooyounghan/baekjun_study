import sys
N, W = map(int, input().split())

nodes = [0] * (500001)

for i in range(N - 1):
    node1, node2 = map(int, sys.stdin.readline().split())
    nodes[node1] += 1
    nodes[node2] += 1


leaf_cnt = 0
for i in range(1, N + 1):
    if nodes[i] == 1:
        leaf_cnt += 1

result = W / leaf_cnt
print(round(result, 10))