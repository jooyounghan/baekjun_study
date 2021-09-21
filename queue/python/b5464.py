from sys import stdin

N, M = map(int, stdin.readline().split())

prices = [0] * N
weights = [0] * (M + 1)

parking = [0] * N

front = 0
rear = 0
waiting = [0] * M

result = 0

def check_available():
    for i in range(N):
        if parking[i] == 0:
            return i
    return -1   

def check_where(car):
    for i in range(N):
        if parking[i] == -car:
            return i
    return -1   

for i in range(N):
    prices[i] = int(stdin.readline())

for j in range(1, M + 1):
    weights[j] = int(stdin.readline())

for i in range(2 * M):
    car = int(stdin.readline())
    if car > 0:
        available = check_available()
        if available >= 0:
            parking[available] = car
        else:
            waiting[rear] = car
            rear += 1
    else:
        parked = check_where(car)
        parking[parked] = 0
        result += prices[parked] * weights[-car]

        if rear > front:
            parking[parked] = waiting[front]
            front += 1
        
print(result)