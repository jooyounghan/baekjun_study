def is_prime(number):
    for i in range(2, int(number ** (1 / 2)) + 1):
        if not number % i:
            return False
    return True

def is_special_prime(N, digits, temp_num):
    if N == digits:
        print(temp_num)
        return

    for i in range(10):
        if not digits and (i == 0 or i == 1 or i == 4 or i == 6 or i == 8 or i == 9):
            continue
        new_temp_num = temp_num * 10 + i
        if is_prime(new_temp_num):
            is_special_prime(N, digits + 1, new_temp_num)

    return

N = int(input())
is_special_prime(N, 0, 0)