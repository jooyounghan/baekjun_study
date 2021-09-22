from sys import stdin

tc = 1
while True:
    L, P, V = map(int, stdin.readline().split())
    if L == 0 and P == 0 and V == 0:
        break
    division = V // P
    remainder = V % P
    remainder = L if L < remainder else remainder
    result = division * L + remainder
    print("Case {}: {}".format(tc, result))
    tc += 1