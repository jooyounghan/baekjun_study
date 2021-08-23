T = int(input())
for tc in range(1, T + 1):
    texts = input().split()
    texts = texts[::-1]
    print("Case #{}: {}".format(tc, " ".join(texts)))