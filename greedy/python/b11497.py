T = int(input())
for tc in range(T):
    nums = int(input())
    height_list = list(map(int, input().split()))
    num_list = sorted(height_list)
    for idx in range(nums):
        if idx % 2:
            height_list[-(idx + 1) // 2] = num_list[idx]
        else:
            height_list[idx // 2] = num_list[idx]
    max_sum = 0
    for idx in range(nums):
        temp = 0
        if idx == nums - 1:
            temp = height_list[0] - height_list[-1]
        else:
            temp = height_list[idx] - height_list[idx + 1]
        temp = -temp if temp < 0 else temp
        if temp > max_sum:
            max_sum = temp
    print(max_sum)