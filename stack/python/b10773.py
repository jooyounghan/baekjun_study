import sys

note = [0] * 100000
N = int(input())
idx = 0
for i in range(N):
    temp = int(sys.stdin.readline())
    if temp:
        note[idx] = temp
        idx += 1
        continue
    idx -= 1
    note[idx] = 0

total = 0
for i in range(idx):
    total += note[i]

print(total)