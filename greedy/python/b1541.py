texts = input()
texts = texts + " "
flag = False
result = 0
idx = 0
nums = 0
for i, text in enumerate(texts) :
    if text == "-" or text == "+" or text == " " :
        if flag :
            result -= int(texts[idx: idx+nums])
        else :
            result += int(texts[idx: idx+nums])
        if text == "-" :
            flag = True
        idx = i + 1
        nums = 0
        continue
    nums += 1
        
print(result)
    