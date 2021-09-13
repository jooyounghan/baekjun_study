N = int(input())
connects = list(map(int, input().split()))
adjacent = [[] for _ in range(N)]

nums = 0

for idx, connect in enumerate(connects):
    if connect == -1:
        root = idx
    else:
        adjacent[connect].append(idx)

visited = [0] * N

def cnt_leaf(start):
    global adjacent, nums
    temp_num = 0
    for adj in adjacent[start]:
        if visited[adj]:
            continue
        temp_num += 1
        cnt_leaf(adj)
    if temp_num:
        return
    else:
        nums += 1

removal = int(input())
visited[removal] = 1
if root == removal:
    print(0)
else:
    cnt_leaf(root)
    print(nums)
