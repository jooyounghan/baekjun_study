from sys import stdin
input = stdin.readline

def check():
    N = int(input())
    result = [0] * 100000
    stack_idx = -1
    max_num = 1

    result_text = []
    for i in range(N):
        t = int(input())
        if stack_idx >= 0:
            if t == result[stack_idx]:
                stack_idx -= 1
                result_text.append("-\n")
            elif t < result[stack_idx]:
                return "NO"

            else:
                for j in range(max_num, t + 1):
                    stack_idx += 1
                    result_text.append("+\n")
                    result[stack_idx] = j
                stack_idx -= 1
                result_text.append("-\n")
                max_num = t + 1

        else:
            for j in range(max_num, t + 1):
                stack_idx += 1
                result_text.append("+\n")
                result[stack_idx] = j
            stack_idx -= 1
            result_text.append("-\n")
            max_num = t + 1

    return "".join(result_text)

print(check())