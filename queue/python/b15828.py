from collections import deque
from sys import stdin

N = int(stdin.readline())

routers = deque()

while True:
    packet = int(stdin.readline())
    if packet == -1:
        break
    if packet == 0:
        routers.popleft()
        continue
    if len(routers) < N:
        routers.append(packet)

if len(routers):
    print(" ".join(map(str, routers)))
else:
    print("empty")