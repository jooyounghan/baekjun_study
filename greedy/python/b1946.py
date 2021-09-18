import sys

T = int(sys.stdin.readline())

grades = [0] * 100001

for tc in range(T):
    N = int(sys.stdin.readline())
    for i in range(N):
        g1, g2 = map(int, sys.stdin.readline().split())
        grades[g1] = g2
    
    cmp_int = grades[1]
    cnt = 1
    for i in range(2, N + 1):
        if cmp_int > grades[i]:
            cmp_int = grades[i]
            cnt += 1
    print(cnt)