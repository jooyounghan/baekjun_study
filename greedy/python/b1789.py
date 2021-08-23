nums = int(input())
num = 0
for i in range(1, nums+1) :
    nums -= i
    if nums >= 0 :
        num += 1
        continue
    else :
        break
print(num)