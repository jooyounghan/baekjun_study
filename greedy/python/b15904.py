sentences = input()
result = []
UCPC = "UCPC"
start_idx = 0
flag = False
for ch in sentences :
    if ch == UCPC[start_idx] :
        result.append(ch)
        start_idx += 1
    if start_idx == 4 :
        flag = True
        break

if flag :
    print("I love UCPC")
else : 
    print("I hate UCPC")