from collections import deque

N = int(input())
area_aet = deque()

check = [list(map(int, input().split())) for _ in range(N)]

check.sort(key = lambda x : x[1], reverse = True)

result = 0
area_set = deque()

for i in range(N):
    xyset = check[i]
    x = xyset[0]
    y = xyset[1]

    if i == 0:
        area_set.append(check[i])
        result += y
        continue

    left_x, left_y = area_set[0]
    right_x, right_y = area_set[-1]

    if x < left_x and y <= left_y:
        area_set.appendleft(xyset)
        result += y * (left_x - x)
    
    if x > right_x and y <= right_y:
        area_set.append(xyset)
        result += y * (x - right_x)

print(result)