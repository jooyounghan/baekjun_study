N = int(input())
ropes = [0] * N
for i in range(N):
    ropes[i] = int(input())
ropes.sort()
mV = 0
for i in range(N):
    temp = ropes[i] * (N - i)
    if mV < temp:
        mV = temp
print(mV)