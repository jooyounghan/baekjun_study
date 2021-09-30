from sys import stdin
N = int(stdin.readline())
nums = list(map(int, stdin.readline().split()))

flag = True
cnt = 0
while flag:
    flag &= False
    for i in range(N):
        if nums[i] > 1:
            cnt += nums[i] % 2
            nums[i] = nums[i] >> 1
            flag |= True
    if flag:
        cnt += 1

for i in range(N):
    if nums[i] > 0:
        cnt += 1
print(cnt)