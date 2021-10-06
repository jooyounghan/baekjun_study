from sys import stdin
input = stdin.readline

for tc in range(int(input())):
    N = int(input())
    left = list(map(int, input().split()))
    left_checked = [0] * N
    right = list(map(int, input().split()))

    result = 0
    for i in range(N):
        if left[i] + 1500 in right:
            result += 1
    print(result)
