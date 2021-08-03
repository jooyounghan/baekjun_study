test_case = int(input())

times = list(map(int, input().split(" ")))
times.sort()
total = 0
for i in range(len(times)) :
    total += sum(times[0:i+1])

print(total)