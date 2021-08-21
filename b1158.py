N, K = map(int, input().split())

circle = [i for i in range(1, N + 1)]
Josephus = []
start_idx = 0
while len(Josephus) < N:
    start_idx = (start_idx + K - 1) % len(circle)
    Josephus.append(circle.pop(start_idx))
print("<{}>".format(", ".join(map(str,Josephus))))