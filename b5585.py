changes = [500, 100, 50, 10, 5, 1]
money = int(input())
money = 1000 - money
cnt = 0
for change in changes :
    cnt += money // change
    money = money % change
print(cnt)