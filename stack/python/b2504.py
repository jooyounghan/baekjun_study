parenth = list(input().strip())

parenth_table = {")" : "(", "]" : "["}

idx = 1

while len(parenth) > 1:
    if idx > len(parenth) - 1:
        parenth = ["0"]
        break

    temp = parenth[idx]
    # 끝나는 괄호일 경우
    if parenth_table.get(temp):
        # 괄호가 바로 닫히는 경우
        if parenth[idx - 1] == parenth_table[temp]:
            del parenth[idx - 1 : idx + 1]
            if temp == ")":
                parenth.insert(idx - 1, "2")
            else :
                parenth.insert(idx - 1, "3")
            idx -= 1
            continue
        # 숫자가 있고, 그 뒤 자리에서 괄호가 닫힐 경우
        elif parenth[idx - 1].isdecimal():
            temp_num = int(parenth[idx - 1])
            if idx > 1 and parenth[idx - 2] == parenth_table[temp]:
                del parenth[idx - 2 : idx + 1]
                if temp == ")":
                    parenth.insert(idx - 2, str(temp_num * 2))
                else:
                    parenth.insert(idx - 2, str(temp_num * 3))
                idx -= 2
                continue
        # 괄호가 닫히지 않고 숫자도 있지 않은 경우(잘못된 괄호식)
        parenth.clear()
        parenth = ["0"]
        break

    # 숫자로 끝나는 경우
    elif temp.isdecimal():
        # 숫자 + 숫자의 경우 서로를 더한다.
        if parenth[idx - 1].isdecimal():
            parenth[idx - 1] = str(int(temp) + int(parenth[idx - 1]))
            del parenth[idx]
            idx -= 1
        # 괄호 + 숫자일 경우 다음 연산을 확인한다, 숫자 + 숫자일 경우 원래 자리에서 연산을 한다.
        idx += 1

    # 시작하는 괄호일 경우 다음 연산을 확인한다
    else:
        idx += 1

# 마지막 남은 식이 괄호이거나 숫자가 아닐 경우 0으로 바꾸어 준다.
parenth[0] = parenth[0] if parenth[0].isdecimal() else 0

print(parenth[0])