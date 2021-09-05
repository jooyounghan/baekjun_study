L, C = map(int, input().split())
base = input().split()
base.sort()
vowels = "aeiou"


def backtracking(cons, vowel, pos, temp_text_list):
    if cons + vowel == L and cons >= 2 and vowel >= 1:
        print("".join(temp_text_list))
        return

    if cons + vowel > L or pos >= C:
        return

    temp_text_list.append(base[pos])
    if base[pos] in vowels:
        backtracking(cons, vowel + 1, pos + 1, temp_text_list)
    else:
        backtracking(cons + 1, vowel, pos + 1, temp_text_list)
    temp_text_list.pop()
    backtracking(cons, vowel, pos + 1, temp_text_list)


backtracking(0, 0, 0, [])
