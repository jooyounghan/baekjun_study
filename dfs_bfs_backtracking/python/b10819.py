N = int(input())
nums = list(map(int, input().split()))
visited = [0] * N
max_num = 0

def bt(cnt, temp, latter):
    global N, max_num
    if cnt == N:
        if max_num < temp:
            max_num = temp
        return
    
    if cnt == 0:
        for i in range(N):
            visited[i] = 1
            bt(cnt + 1, temp, nums[i])
            visited[i] = 0
    else:
        for i in range(N):
            if not visited[i]:
                visited[i] = 1
                temp_sum = nums[i] - latter if nums[i] > latter else latter - nums[i]
                bt(cnt + 1, temp + temp_sum, nums[i])
                visited[i] = 0
    return

bt(0, 0, 0)
print(max_num)