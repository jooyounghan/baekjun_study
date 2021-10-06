from sys import stdin
from collections import deque

input = stdin.readline

N = int(input())
infos = list(map(int, input().split()))
round_queue = deque()
for i in range(N):
    round_queue.append([i + 1, infos[i]])
result = []
while True:
    popped = round_queue.popleft()
    result.append(popped[0])
    if len(round_queue):
        if popped[1] > 0:
            for i in range(popped[1] - 1):
                round_queue.append(round_queue.popleft())
        else:
            for i in range(-popped[1]):
                round_queue.appendleft(round_queue.pop())
    else:
        break

print(*result)