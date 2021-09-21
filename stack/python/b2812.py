N, K = map(int, input().split())
numbers = input()
cnt = N - K

check_stack = [numbers[0]]

for number in numbers[1:]:
    while K and check_stack and number > check_stack[-1]:
        K -= 1
        check_stack.pop()

    if cnt > len(check_stack):
        check_stack.append(number)
    else:
        break

print("".join(check_stack))