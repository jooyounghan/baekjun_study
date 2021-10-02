def check(nums):
    cnt = 0
    while nums:
        if nums % 2:
            cnt += 1
        nums = nums >> 1
    return cnt

N, K = map(int, input().split())

buy = 0
times = 1
while check(N) > K:
    if N & 1:
        buy += times
        N += 1
    N = N >> 1
    times *= 2

print(buy)