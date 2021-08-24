N = int(input())

bar1 = list(map(int,input().split()))
bar2 = []
bars = [bar1, bar2]
position = [0] * (N + 1)

stack_log = []

for max_num in range(N, 0, -1):
    main_bar = bars[position[max_num]]
    sub_bar = bars[not position[max_num]]
    while main_bar[-1] < max_num:
        stack_log.append("{} {}".format(position[max_num] + 1, int(not position[max_num]) + 1))
        temp = main_bar.pop()
        position[temp] = not position[temp]
        sub_bar.append(temp)
    stack_log.append("{} {}".format(position[max_num] + 1, 3))
    main_bar.pop()

print(len(stack_log))
for i in range(len(stack_log)):
    print(stack_log[i])