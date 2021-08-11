coins_value = [0] * 10
num_coins, values = map(int, input().split())

for i in range(num_coins):
    coins_value[i] = int(input())

result = 0
for i in range(num_coins - 1, -1, -1):
    result += values // coins_value[i]
    values = values % coins_value[i]
    if not values:
        break
    
print(result)